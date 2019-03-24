#include <msp430f249.h>
#define uchar unsigned char
#define uint unsigned int

uchar const LED_Lib[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void tube1(uint t)
{
  P1OUT = LED_Lib[t % 10];
}

void tube2(uint t)
{ 
  P1OUT = LED_Lib[(t / 10) % 10];
  if (t < 10) P1OUT = 0x00;
}

void tube3(uint t)
{ 
  P1OUT = LED_Lib[(t / 100) % 10];
  if ((t / 10) < 10) P1OUT = 0x00;
}

void tube4(uint t)
{ 
  P1OUT = LED_Lib[(t / 1000) % 10];
  if ((t / 100) < 10) P1OUT = 0x00;
}