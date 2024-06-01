#include <avr/io.h>
#include <avr/interrupt.h>
#include <LCD.h>
#define checkbit(x, y) ((x) & (y)) // Macro to check a specific bit in a byte
#define bitn(p) (0x01 << (p)) // Macro to generate a bitmask for a given bit position
LCD lcd;
long result, average; // Variables to store ADC result and average
int num1, num2;
int i = 0;
char operatorz = ' ';
bool isSecondNumber = false; // Flag to indicate if the second number is being input

// Initialize ADC with appropriate settings
void init_ADC() {
    ADMUX = 0x44; // Select Vref=AVcc and select channel 4 (PC4)
    ADCSRA = 0xC7; // Enable ADC, start conversion, auto trigger enable, interrupt enable
}

// Read ADC value and return it
long read_ADC() {
    ADCSRA |= (1 << ADSC); // Start conversion
    while (checkbit(ADCSRA, (1 << ADSC))); // Wait for conversion to complete
    return ADCW; // Read ADC value
}

// Clear the LCD and reset variables
void clear() {
    lcd.cmd(0x01); // Clear LCD
    num1 = 0;
    num2 = 0;
    operatorz = ' ';
    result = 0;
    average = 0;
    i = 0;
    isSecondNumber = false;
}

// Perform arithmetic operation based on the operator
void performOperation() {
    switch (operatorz) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                result = 0; // Handle division by zero
            }
            break;
        default:
            result = num1; // Default to first number if no operator
            break;
    }
    lcd.string("=");
    lcd.showvalue(result); // Display the result on the LCD
    _delay_ms(500);
    clear(); // Reset for next calculation
}

// Compare ADC value ranges and update the display and operands
void compare() {
    if (average > 519 && average < 523) {
        lcd.string("1");
        if (isSecondNumber) num2 = num2 * 10 + 1; else num1 = num1 * 10 + 1;
    } else if (average > 690 && average < 694) {
        lcd.string("2");
        if (isSecondNumber) num2 = num2 * 10 + 2; else num1 = num1 * 10 + 2;
    } else if (average > 766 && average < 770) {
        lcd.string("3");
        if (isSecondNumber) num2 = num2 * 10 + 3; else num1 = num1 * 10 + 3;
    } else if (average > 1018 && average < 1023) {
        lcd.string("+");
        operatorz = '+';
        isSecondNumber = true;
    } else if (average > 489 && average < 493) {
        lcd.string("4");
        if (isSecondNumber) num2 = num2 * 10 + 4; else num1 = num1 * 10 + 4;
    } else if (average > 639 && average < 642) {
        lcd.string("5");
        if (isSecondNumber) num2 = num2 * 10 + 5; else num1 = num1 * 10 + 5;
    } else if (average > 704 && average < 708) {
        lcd.string("6");
        if (isSecondNumber) num2 = num2 * 10 + 6; else num1 = num1 * 10 + 6;
    } else if (average > 910 && average < 914) {
        lcd.string("-");
        operatorz = '-';
        isSecondNumber = true;
    } else if (average > 473 && average < 478) {
        lcd.string("7");
        if (isSecondNumber) num2 = num2 * 10 + 7; else num1 = num1 * 10 + 7;
    } else if (average > 611 && average < 615) {
        lcd.string("8");
        if (isSecondNumber) num2 = num2 * 10 + 8; else num1 = num1 * 10 + 8;
    } else if (average > 671 && average < 675) {
        lcd.string("9");
        if (isSecondNumber) num2 = num2 * 10 + 9; else num1 = num1 * 10 + 9;
    } else if (average > 856 && average < 869) {
        lcd.string("*");
        operatorz = '*';
        isSecondNumber = true;
    } else if (average > 461 && average < 465) {
        clear();
    } else if (average > 591 && average < 595) {
        lcd.string("0");
        if (isSecondNumber) num2 = num2 * 10 + 0; else num1 = num1 * 10 + 0;
    } else if (average > 817 && average < 822) {
        lcd.string("/");
        operatorz = '/';
        isSecondNumber = true;
    } else if (average > 647 && average < 650) {
        performOperation();
    }
    _delay_ms(300); // Debounce delay
}

int main(void) {
    lcd.init();
    lcd.cmd(0x0C); // Display on, cursor off
    lcd.line1(0);
    init_ADC();
    while (1) {
        average = read_ADC();
        compare();
    }
}
