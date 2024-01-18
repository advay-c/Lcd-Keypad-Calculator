# AVR Calculator

This is a simple calculator implemented on an AVR microcontroller using C language. The calculator takes input from an analog sensor, performs basic arithmetic operations, and displays the result on an LCD.

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
int i=0;
long result, average;
int count = 0;
int num = 0;
int num1,num2;
int function;
int equal=0;
int answer=0;
int position=0;
```
- lcd: Instance of the LCD class.
- i: Counter variable.
- result, average: Variables for storing ADC results.
- count: Counter for tracking the number of button presses.
- num: Current digit or operator entered.
- num1, num2: Variables to store operands.
- function: Variable representing the selected arithmetic operation.
- equal: Flag indicating if the "=" button is pressed.
- answer: Variable to store the result of arithmetic operations.
- position: Variable to track the position on the LCD.
  
# Main Function
```c
Copy code
int main(void)
{
  // Initialization of LCD
  lcd.init();
  lcd.cmd(0x0C);
  lcd.line1(0);

  while(1)
  {
    // ADC configuration
    ADMUX = 0x44;
    ADCSRA = 0xC7;

    // ADC conversion
    while(checkbit(ADCSRA, bitn(ADSC)));
    result += ADCW;
    i++;

    // Average calculation and comparison
    if (i > 99)
    {
      average = result / 100;
      compare();
      result = 0;
      average = 0;
      i = 0;
    }
  }
}
```
The main function initializes the LCD and enters an infinite loop for continuous operation. It configures and reads analog input using the ADC, calculates the average, and calls the compare function for button detection and arithmetic operations.

# Compare Function
```c
Copy code
void compare()
{
  // Arithmetic operations
  // ...

  // Digit and operator detection
  // ...

  // Operand and operator handling
  // ...
}
```
The compare function handles arithmetic operations and detects pressed buttons based on the average ADC value. It updates the display and sets flags for the main loop to perform the corresponding operations.

# Usage
Connect the AVR microcontroller to the analog sensor and LCD display. Upload the code to the microcontroller and power it on to use the calculator.

Feel free to customize the code to add more features or optimize performance.
