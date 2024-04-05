#include<avr/io.h>
#include <avr/interrupt.h>
#include<LCD.h>
#define checkbit(x, y) ((x) & (y))
#define bitn(p) 0x01 << (p))
LCD lcd;
int i=0; 
long result, average;
int num1,num2, count;
int function; 
int answer=0; 
char operatorz = ' ';
int main (void)
{
  lcd.init();
  lcd.cmd(0x0C);
  lcd.line1(0);
while(1)
{
ADMUX = 0x44;
ADCSRA = 0xC7;
while(checkbit(ADCSRA, (bitn(ADSC)));
result += ADCW;
i++;
if (i>99)
{
   average = result/100;
   compare();
   compare1();
   answer = 0;
   result = 0;
   average = 0;
   i=0;
}
}
}

void compare() {
  
if (average > 519 && average < 523)
{
 lcd.string("1");
 num1 += 1;
 _delay_ms(300);
}
if (average > 690 && average < 694)
{
  lcd.string("2");
  num1 += 2;
  _delay_ms(300);
}
if (average > 766 && average < 770)
{
  lcd.string("3");
  num1 += 3;
  _delay_ms(300);
}
if (average > 1018 && average < 1023)
{
  lcd.string("+");
  operatorz = '+';
  _delay_ms(300);
}
if (average > 489 && average < 493)
{
  lcd.string("4");
  num1 += 4;
  _delay_ms(300);
}
if (average > 639 && average < 642)
{
  lcd.string("5");
  num1 += 5;
  _delay_ms(300);
}
if (average > 704 && average < 708)
{
  lcd.string("6");
  num1 += 6;
  _delay_ms(300);
}
if (average > 910 && average < 914)
{
  lcd.string("-");
  operatorz = '-';
  _delay_ms(300);
}
if (average > 473 && average < 478)
{
  lcd.string("7");
  num1 += 7;
  _delay_ms(300);
}
if (average > 611 && average < 615)
{
  lcd.string("8");
  num1 += 8;
  _delay_ms(300);  
}
if (average > 671 && average < 675)
{
  lcd.string("9");
  num1 += 9;
  _delay_ms(300);  
}
if (average > 856 && average < 869)
{
  lcd.string("*");
  operatorz = '*';
  _delay_ms(300);
}
if (average > 461 && average < 465)
{
  lcd.cmd(0x01);
  num1 = 0;
  num2 = 0;
  answer = 0;
}
if (average > 591 && average < 595)
{
  lcd.string("0");
  num1 += 0;
  _delay_ms(300);
}
if (average > 817 && average < 822)
{
  lcd.string("/");
  operatorz = '/';
  _delay_ms(300);
}
if (operatorz == '/') {
  answer = num1/num2;
}
else if (operatorz == '+') {
  answer = num1 + num2;
}
else if (operatorz == '-') {
  answer = num1 - num2;
}
else if (operatorz == '*') {
  answer = num1 * num2;
}
}

void compare1() {
  
if (average > 519 && average < 523)
{
 num2 += 1;
 _delay_ms(300);
}
if (average > 690 && average < 694)
{
  num2 += 2;
  _delay_ms(300);
}
if (average > 766 && average < 770)
{
  num2 += 3;
  _delay_ms(300);
}
if (average > 489 && average < 493)
{
  num2 += 4;
  _delay_ms(300);
}
if (average > 639 && average < 642)
{
  num2 += 5;
  _delay_ms(300);
}
if (average > 704 && average < 708)
{
  num2 += 6;
  _delay_ms(300);
}
if (average > 473 && average < 478)
{
  num2 += 7;
  _delay_ms(300);
}
if (average > 611 && average < 615)
{
  num2 += 8;
  _delay_ms(300);  
}
if (average > 671 && average < 675)
{
  num2 += 9;
  _delay_ms(300);  
}
if (average > 461 && average < 465)
{
  lcd.cmd(0x01);
  num1 = 0;
  num2 = 0;
  answer = 0;
}
if (average > 591 && average < 595)
{
  num2 += 0;
  _delay_ms(300);
}
if (average > 647 && average < 650)
{
  operatorz = '=';
  lcd.string("=");
  lcd.showvalue(answer/2);
  _delay_ms(500);
}
}
