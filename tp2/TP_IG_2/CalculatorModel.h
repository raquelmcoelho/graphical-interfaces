/** -*- c-basic-offset: 3 -*-
 * @file   CalculatorModel.h
 * @author Sebastien Fourey
 *
 * @brief  Implementation of a basic 4 operations calculator.
 */
#ifndef GUI_LAB_CALCULATOR_MODEL_H
#define GUI_LAB_CALCULATOR_MODEL_H

#include <QString>

/*
 *  A basic 4 operation calculator class
 */
class CalculatorModel {

public:
  /*
   * Enum type for the base
   *
   */
  enum Base
  {
    Bin = 2,
    Dec = 10,
    Hex = 16
  };

  /*
   *  Enum type for the button IDs
   */
  enum ButtonID
  {
    Button_0 = 0,
    Button_1,
    Button_2,
    Button_3,
    Button_4,
    Button_5,
    Button_6,
    Button_7,
    Button_8,
    Button_9,
    Button_A,
    Button_B,
    Button_C,
    Button_D,
    Button_E,
    Button_F,
    Button_Dot,
    Button_Plus,
    Button_Minus,
    Button_Divide,
    Button_Multiply,
    Button_Equal,
    Button_Clear,
    Button_Count
  };

  CalculatorModel();

  /**
   * Achieve an operation.
   *
   * @param c The operation's code (ButtonID).
   * @return true if the text to be displayed has been modified,
   *         otherwise false.
   */
  bool command(ButtonID id);

  /**
   * Get the current text to be displayed.
   *
   * @return The current text.
   */
  QString getText() const;

  /**
   * Set the base.
   *
   * @param base
   */
  void setBase(Base base);

  /**
   * Get the current base.
   *
   * @return The current value of the base.
   */
  Base base();

private:
  /**
   * Add a character to the display.
   *
   * @param c A char to be added.
   * @return true if the text has been changed, otherwise false (for
   *         example if c is a dot and the display already has one).
   */
  bool addChar(char c);

  /**
   * Achieve an operation when the second operand was expected.
   *
   * @return true if an operation was indeed to be achieved.
   */
  bool achieveEqual();

  /**
   * Return the value (as a double) of the current operand.
   *
   * @return
   */
  double getOperand() const;

  /**
   * Set the display value using current base, given a double.
   *
   * @param x
   */
  void setText(double x);

  /*
   * Private fields
   */

  QString _text;   /**< The display text */
  double _memory;  /**< The first operand */
  char _operation; /**< Code of the current operation  */
  bool _newNumber; /**< Are we expecting a new number?  */
  Base _base;      /**< The base of numeration */
};

#endif // defined(GUI_LAB_CALCULATOR_MODEL_H)
