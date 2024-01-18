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

### Compare Function

```c
void compare()
{
  if (function == 1 && equal == 1)
  { 
    answer = num2 + num1;
    lcd.showvalue(answer);
    _delay_ms(500);
    equal = 0;
    function = 0;
  }
  
  if (function == 2 && equal == 1)
  {
    answer = num1 - num2;
    lcd.showvalue(answer); 
    _delay_ms(500);
    equal = 0;
    function = 0;
  }
  
  if (function == 3 && equal == 1)
  {
    answer = num1 * num2;
    lcd.showvalue(answer);
    _delay_ms(500);
    equal = 0;
    function = 0;
  }
  
  if (function == 4 && equal == 1)
  {
    answer = num1 / num2;
    lcd.showvalue(answer);
    _delay_ms(500);
    equal = 0;
    function = 0;
  }
  
  if (average > 519 && average < 522)
  {
    lcd.string("1");
    count++;
    num = 1;
    _delay_ms(300);
  }
  
  if (average > 690 && average < 694)
  {
    lcd.string("2");
    count++;
    num = 2;
    _delay_ms(300);
  }
  
  if (average > 766 && average < 770)
  {
    lcd.string("3");
    count++;
    num = 3;
    _delay_ms(300);
  }
  
  if (average > 1018 && average < 1023)
  {
    lcd.string("+");
    count = 0;
    function = 1;
    equal = 0;
    _delay_ms(300);
  }
  
  if (average > 489 && average < 493)
  {
    lcd.string("4");
    count++;
    num = 4;
    _delay_ms(300);
  }
  
  if (average > 639 && average < 642)
  {
    lcd.string("5");
    count++;
    num = 5;
    _delay_ms(300);
  }
  
  if (average > 702 && average < 708)
  {
    lcd.string("6");
    count++;
    num = 6;
    _delay_ms(300);
  }
  
  if (average > 909 && average < 914)
  {
    lcd.string("-");
    count = 0;
    function = 2;
    equal = 0;
    _delay_ms(300);
  }
  
  if (average > 472 && average < 478)
  {
    lcd.string("7");
    count++;
    num = 7;
    _delay_ms(300);
  }
  
  if (average > 610 && average < 615)
  {
    lcd.string("8");
    count++;
    num = 8;
    _delay_ms(300);  
  }
  
  if (average > 671 && average < 677)
  {
    lcd.string("9");
    count++;
    num = 9;
    _delay_ms(300);  
  }
  
  if (average > 856 && average < 862)
  {
    lcd.string("*");
    count = 0;
    function = 3;
    equal = 0;
    _delay_ms(300);
  }
  
  if (average > 460 && average < 465)
  {
    lcd.cmd(0x01);
    count = 0;
    num = 0;
    num1 = 0;
    num2 = 0;
    function = 0;
    equal = 0;
    answer = 0;
  }
  
  if (average > 591 && average < 595)
  {
    lcd.string("0");
    count++;
    num = 0;
    _delay_ms(300);
  }
  
  if (average > 647 && average < 650)
  {
    lcd.string("=");
    equal = 1;
    _delay_ms(500);
  }
  
  if (average > 817 && average < 822)
  {
    lcd.string("/");
    count = 0;
    function = 4;
    equal = 0;
    _delay_ms(300);
  }
  
  if (count == 1)
  {
    num1 = num;
  }
  
  if (count == 2)
  {
    num2 = num;
    count = 0;
  }
}

```
The compare function handles arithmetic operations and detects pressed buttons based on the average ADC value. It updates the display and sets flags for the main loop to perform the corresponding operations.

# Usage
Connect the AVR microcontroller to the analog sensor and LCD display. Upload the code to the microcontroller and power it on to use the calculator.

Feel free to customize the code to add more features or optimize performance.
