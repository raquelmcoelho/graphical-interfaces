/**
 * @file   ColorWidget.cpp
 * @author Sebastien Fourey
 */
#include <QPainter>
#include <QBrush>
#include "ColorWidget.h"

ColorWidget::ColorWidget(QWidget * parent) //
    : QWidget(parent), _bgColor(10, 20, 30)
{
  setAutoFillBackground(false); // Prevent blinking when repainting.
}

ColorWidget::~ColorWidget() {}

void ColorWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(rect(), QBrush(_bgColor));
}

void ColorWidget::changeColor()
{
  int r = rand() % 255;
  int g = rand() % 255;
  int b = rand() % 255;
  _bgColor.setRgb(r, g, b);
  repaint(rect());
  emit colorChanged(r, g, b);
}
