#include <LPC21xx.h>

#include "types.h"
#include "define.h"
#include "adc_define.h"
#include "delay.h"
	  


void Init_ADC(void)
{
  PINSEL1 &= ~(0xff<<22);
  PINSEL1|=0x01000000;
  ADCR |=(CLKDIV<<CLKDIV_START_BIT)|(1<<PDN_BIT);
}

void Read_ADC(u32 chNo,u32 *adcVal,f32 *eAR)
{
	ADCR &= 0xffffff00;
	ADCR |= (1<<chNo)|(1<<ADC_START_BIT);
	delay_us(3);
	while(((ADDR>>DONE_BIT)&1)==0);
	ADCR &= ~(1<<ADC_START_BIT);
	*adcVal = ((ADDR>>RESULT_START_BIT)&1023);
	*eAR = ((*adcVal)*(3.3/1023));
} 

/*f32 Read_ADC(u8 chNo)
{
        u16 adcVal=0;
        f32 eAR;
        WRITEBYTE(ADCR,0,chNo);
        SETBIT(ADCR,ADC_START_BIT);
        delay_us(3);
        while(!READBIT(ADDR,DONE_BIT));
        CLRBIT(ADCR,ADC_START_BIT);
        adcVal=(ADDR>>6)&0x3FF;
        eAR=((adcVal*3.3)/1023);
        return eAR;
} */
/*void Init_ADC(void)
{
PINSEL1 |=(1<<24);
AD0CR=(1<<1)|(4<<8)|(1<<21);

}
INT Read_ADC(U8 CHnO)
{
	ADOCR |=(1<<24);
	while(!(ADODR1&(1<<31)));
	return (AD0DR1>>6)&0X3FF;

} */


