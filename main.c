#include <msp430f249.h>
#include "tube.h"
#define uchar unsigned char
#define uint unsigned int

void initialize(void)
{
  P1DIR = 0xFF;
  P1OUT = 0x00;
  P1SEL = 0X00;
  
  P2DIR = BIT0 + BIT1 + BIT2 + BIT3;
  P2OUT &=~ (BIT0 + BIT1 + BIT2 + BIT3);
}

void delayus(uint t)
{
  uchar i;
  while(t--)
    for(i=255;i>0;i--);
}


void main( void )
{
  // Stop watchdog timer to prevent time out reset
  uint count;
  WDTCTL = WDTPW + WDTHOLD;
  initialize();
  while(1)
  {
    for(count = 9999;count > 0;--count)
    {
      tube1(count);
      P2OUT |= BIT0;
      P2OUT &=~ BIT0;
      
      tube2(count);
      P2OUT |= BIT1;
      P2OUT &=~ BIT1;
      
      tube3(count);
      P2OUT |= BIT2;
      P2OUT &=~ BIT2;
      
      tube4(count);
      P2OUT |= BIT3;
      P2OUT &=~ BIT3;
      delayus(100);
      
    }
  }


}
