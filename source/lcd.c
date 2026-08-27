#include<lpc21xx.h>
#include"lcd_define.h"
#include"delay.h"
#include"types.h"
void writeLCD(unsigned int dat)
{
IOCLR0=1<<LCD_RW;
IOPIN0=(IOPIN0&~(255<<LCD_DATA))|(dat<<LCD_DATA);
IOSET0=1<<LCD_EN;
delay_us(1);
IOCLR0=1<<LCD_EN;
delay_ms(2);
}
void cmdLCD(unsigned char cmd)
{
IOCLR0=1<<LCD_RS;
writeLCD(cmd);
}
void charLCD(unsigned char asciival)
{
IOSET0=1<<LCD_RS;
writeLCD(asciival);
}

void initLCD(void)
{
IODIR0|=0XFF<<LCD_DATA;
IODIR0|=7<<LCD_RS;
delay_ms(15);
cmdLCD(0x30);
delay_ms(5);
cmdLCD(0x30);
delay_us(100);
cmdLCD(0x30);
cmdLCD(0x30);
cmdLCD(MODE_8BIT_2LINE);
cmdLCD(DSP_ON_CUR_ON);
cmdLCD(CLEAR_LCD);
cmdLCD(SHIFT_CUR_RIGHT);
}
void strLCD(char *s)
{
while(*s)
{
charLCD(*s++);
}
}
void u32LCD(unsigned int n)
{
int i=0;
unsigned char a[10];
if(n==0)
{
charLCD('0');
}
else
{
while(n)
{
		  a[i++]=(n%10)+48;
		  n=n/10;
		  }
		  for(--i;i>=0;i--)
		  {
		  charLCD(a[i]);
		  }
		  }
 }
void f32LCD(f32 f,u8 nDP)
{
u32 n,i;
if(f<0.0)
{
charLCD ('-');
f=-f;
}
n=f;
u32LCD(n);
charLCD('.');
for(i=0;i<nDP;i++)
{
f=(f-n)*10;
n=f;
charLCD(n+48);
}
}

void binLCD(u32 n,u8 nBD)
{
s32 i;
for(i=nBD;i>=0;i--);
{
charLCD((n>>i&1)+48);
}
}

void hexLCD(u32 n)
{
s32 i=0;
u8 a[8],t;
if(n==0)
charLCD('0');
else
{
while(n>0)
{
t=(n%16);
(t<10)?(t=t+48):(t=(t-10)+'A');
a[i++]=t;
n/=16;
a[i]=n+48;
}
for(--i;i>=0;i--)
charLCD(a[i]);
}
}

void octLCD(u32 n)
{
s32 i=0;
u8 a[8],t;
if(n==0)
charLCD('0');
else
{
while(n>0)
{
((t=(n%8))<10)?(t=t+48):(t=(t-10)+'A');
a[i++]=t;
n/=8;
a[i]=n+48;
}
for(--i;i>=0;i--)
charLCD(a[i]);
}
}

void buildCGRAM(u8 *p,u8 nbytes)
{
u32 i;
//point to cgram start
cmdLCD(GOTO_CGRAM);
for(i=0;i<nbytes;i++)

{
//write to cgram via data reg
charLCD(p[i]);
}
//return back to ddram
//cmdLCD(GOTO_LINE1_POS0);
}
