#include<avr/io.h>
#include <avr/interrupt.h>
#include<LCD.h>
#define checkbit(x, y) ((x) & (y))
#define bitn(p) 0x01 << (p))
LCD Icd;
int i=0; 
long result, average;

int main (void)
{
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while checkbit(ADCSRA, bitn(ADSC)));
    result = result + ADCW;
    i++;
    if (i>99)
    {
      average = result/100;
      Serial.println(average);
      result = 0;
      average = 0;
      i = 0;
    }
  }
}
