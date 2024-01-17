#include<avr/io.h>
#include <avr/interrupt.h>
#include<LCD.h>
#define checkbit(x, y) ((x) & (y))
#define bitn(p) 0x01 << (p))
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
   result = 0;
   average = 0;
   i=0;
}
}
}
void compare()
{
if (function == 0)
{
if (count == 1)
{
  num1 = num*100;
}
if (count == 2)
{
  num2 = num*10;
}
if (count == 3)
{
  num1 = num + num1 + num2;
  _delay_ms(500);
  num=0;
  num2=0;
  count = 0;
}
}
if (function >0)
{
if (count ==1)
{
  num1 = num;
}
if (count ==2)
{
  num2 = num;
}
if (count ==3)
{
  num2 = num + num1 + num2;
  _delay_ms (500);
  count = 0;
  num=0;
  num1=0;
  num2=0;
}
}
if (function == 1 && equal == 1)
{ 
  answer = num2+num1;
  lcd.showvalue(answer);
  _delay_ms(500);
  equal = 0;
  function = 0;
}
if (function == 2 && equal == 1)
{
  answer = num1-num2;
  lcd.showvalue(answer); 
  _delay_ms(500);
  equal = 0;
  function = 0;
}
if (function == 3 && equal == 1)
{
  answer = num1*num2;
  lcd.showvalue(answer);
  _delay_ms(500);
  equal = 0;
  function = 0;
}
if (function == 4 && equal == 1)
{
  answer = num1/num2;
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
  function =1;
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
int count = 0;
int num = 0;
int num1,num2,num3,num4=0;
int function = 0;
int equal = 0;
int answer = 0;
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
}
