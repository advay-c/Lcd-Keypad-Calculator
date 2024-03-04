# AVR Calculator

This is a simple calculator implemented on an AVR microcontroller using the C++ language. The calculator takes input from an analog sensor, performs basic arithmetic operations, and displays the result on an LCD.

## Features

- Addition
- Subtraction
- Multiplication
- Division

## Hardware Requirements

- AVR Microcontroller
- Analog sensor
- LCD Display

## Code Overview

### Macros

```c
#define checkbit(x, y) ((x) & (y))
#define bitn(p) 0x01 << (p)
```
These macros are utility functions used for checking specific bits in a register.

# Global Variables
```c
LCD lcd;
long result, average;
int count = 0;
int num1, num2;
int function;
int equal = 0;
int answer = 0;
char operatorz = ' ';
```
- lcd: Instance of the LCD class.
- result, average: Variables for storing ADC results.
- count: Counter for tracking the number of button presses.
- num1, num2: Variables to store operands.
- function: Variable representing the selected arithmetic operation.
- equal: Flag indicating if the "=" button is pressed.
- answer: Variable to store the result of arithmetic operations.
- operatorz: Variable to store the current arithmetic operator.

# Main Function

```c
int main(void)
{
  lcd.init();
  lcd.cmd(0x0C);
  lcd.line1(0);

  while(1)
  {
    ADMUX = 0x44;
    ADCSRA = 0xC7;

    while(checkbit(ADCSRA, bitn(ADSC)));
    result += ADCW;
    i++;

    if (i > 99)
    {
      average = result / 100;
      compare();
      compare1();
      result = 0;
      average = 0;
      i = 0;
    }
  }
}
```
The main function initializes the LCD and enters an infinite loop for continuous operation. It configures and reads analog input using the ADC, calculates the average, and calls the compare and compare1 functions for button detection and arithmetic operations.

# Compare Functions

```c
void compare() {
  // Button detection and arithmetic operations based on the first operand
}

void compare1() {
  // Button detection and arithmetic operations based on the second operand
}
```
The compare functions handle button detection and arithmetic operations based on the average ADC value.

# Usage
Connect the AVR microcontroller to the analog sensor and LCD display. Upload the code to the microcontroller and power it on to use the calculator.

Feel free to customize the code to add more features or optimize performance.
