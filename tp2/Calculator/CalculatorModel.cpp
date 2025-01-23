/** -*- c-basic-offset: 3 -*-
 * @file   CalculatorModel.cpp
 * @author Sebastien Fourey
 *
 * @brief  Implementation of a basic 4 operations calculator.
 */
#include "CalculatorModel.h"
#include <QRegularExpression>
using namespace std;

CalculatorModel::CalculatorModel()
{
  _text = "0";
  _operation = 0;
  _memory = 0.0;
  _newNumber = true;
  _base = Dec;
}

CalculatorModel::Base CalculatorModel::base()
{
  return _base;
}

void CalculatorModel::setBase(Base base)
{
  if ((base != Dec) && _text.contains(QChar('.'))) {
    _text.replace(QRegularExpression("\\..*"), QString(""));
  }
  bool ok;
  qlonglong value = _text.toLongLong(&ok, _base);
  _base = base;
  setText(ok ? static_cast<double>(value) : 0.0);
}

bool CalculatorModel::command(ButtonID id)
{
  switch (static_cast<int>(id)) {
  case Button_A:
  case Button_B:
  case Button_C:
  case Button_D:
  case Button_E:
  case Button_F:
    return addChar('A' + (id - Button_A));
  case Button_0:
  case Button_1:
  case Button_2:
  case Button_3:
  case Button_4:
  case Button_5:
  case Button_6:
  case Button_7:
  case Button_8:
  case Button_9:
    return addChar('0' + static_cast<char>(id));
  case Button_Dot:
    return addChar('.');
  case Button_Plus:
  case Button_Minus:
  case Button_Multiply:
  case Button_Divide:
    if (!_newNumber) {
      achieveEqual();
    }
    _memory = getOperand();
    _operation = id;
    _newNumber = true;
    return true;
  case Button_Clear:
    setText(0);
    _newNumber = true;
    _operation = 0;
    return true;
  case Button_Equal:
    return achieveEqual();
  }
  return false;
}

bool CalculatorModel::achieveEqual()
{
  double operand = 0.0;
  double result = 0.0;
  if (!_operation) {
    return false;
  }

  operand = getOperand();
  switch (_operation) {
  case Button_Plus:
    result = _memory + operand;
    break;
  case Button_Minus:
    result = _memory - operand;
    break;
  case Button_Divide:
    result = _memory / operand;
    break;
  case Button_Multiply:
    result = _memory * operand;
    break;
  }
  setText(result);
  _newNumber = true;
  _operation = 0;
  return true;
}

bool CalculatorModel::addChar(char c)
{
  if ((c == '.') && (_text.contains('.') || (_base != Dec))) {
    return false;
  }

  if ((_text == "0") && (c == '0')) {
    return false;
  }

  if (((_text == "0") || _newNumber) && (c != '0') && (c != '.')) {
    _text = c;
    _newNumber = false;
    return true;
  }

  if (_newNumber && !(_text == "0" && c == '.')) {
    _text = "";
  }
  _text += c;
  _newNumber = false;
  return true;
}

QString CalculatorModel::getText() const
{
  QString r = _text;
  return r.replace(".", ",");
}

double CalculatorModel::getOperand() const
{
  bool ok = true;
  switch (_base) {
  case Bin:
    return static_cast<double>(_text.toLong(&ok, 2));
  case Dec:
    return _text.toDouble();
  case Hex:
    return static_cast<double>(_text.toLong(&ok, 16));
  }
  return 0;
}

void CalculatorModel::setText(double x)
{
  switch (_base) {
  case Bin:
    _text = QString::number(static_cast<long>(x), 2);
    break;
  case Dec:
    _text = QString::number(static_cast<double>(x), 'g');
    break;
  case Hex:
    _text = QString::number(static_cast<long>(x), 16).toUpper();
    break;
  }
}
