#include<lpc21xx.h>
#include"types.h"
#include"define.h"
#include"kpm_define.h"
#include"lcd.h"
#include"lcd_define.h"
#include"delay.h"
u8 kpmLUT[4][4]={{'1','2','3','+'},
				 {'4','5','6','-'},
				 {'7','8','9','*'},
				 {'*','0','#','='}};
u32 ColScan(void)
{
return((READNIBBLE(IOPIN1,COL0)<15)? 0:1);
}
u32 ROWcheck(void)
{
u32 rNO;
for(rNO=0;rNO<=3;rNO++)
{
WRITENIBBLE(IOPIN1,ROW0,~(1<<rNO));
if(READNIBBLE(IOPIN1,COL0)!=15)   
{
break;
}
}
//reinitiazation all rows
WRITENIBBLE(IOPIN1,ROW0,0);
return rNO;
}

u32 colcheck(void)
{
u32 cNO;
for(cNO=0;cNO<=3;cNO++)
{
if(READBIT(IOPIN1,COL0+cNO)==0)
break;
}
return cNO;
}
u8 KeyScan(void)
{
u32 rNO,cNO;
u8 keyV;
//WAIT TO DETECT ANY KEY PRESS
while(ColScan());
//identify row in which   key was presse
rNO=ROWcheck();
//identify col in which key was pressed
cNO=colcheck();
keyV=kpmLUT[rNO][cNO];
return keyV;
}
void Init_KPM(void)
{
//cfg row lines as gpio output
WRITENIBBLE(IODIR1,ROW0,15);
//HENCE ALL ROWS ARE GROUNDED
//DEFAULTS ALL COLS LINES ARE GPIO INPUT
}                                            
/*u32 ReadNum(void)
{
u8 keyc
	u32 num=0;
	while(1)
	{
	keyc =keyscan();
	if(key>='0'&&keyc<='9')
	{
	num=(num*10)+(keyc-48);
	while(colscan()==0);
	}
	else
	{
	break;
	}
	}
	return num;
	} 
	 */
u32 ReadNum(void)
{
        u8 keyC;
        u32 num=0;
        u32 count=0;
		cmdLCD(0xc0);
        while(1)
        {
				
                keyC=KeyScan();
                if(keyC>='0'&& keyC<='9')
                {
                        count++;
                        charLCD(keyC);
						delay_ms(100);
                     //   cmdLCD(0x06);
                        num=(num*10)+(keyC-48);
                        while(ColScan()==0);
                }
                else if(keyC=='*')
                {
                        if((count>0)&&(num!=0))
                        {
                        num=num/10;
                        cmdLCD(0XC0+count);
                        cmdLCD(0X10);
                        charLCD(' ');
                        cmdLCD(0X10);
                        count--;
                        while(ColScan()==0);
                        }
                        else if(num==0)
                        {
                                while(ColScan()==0);
                        }
                }
                else if(keyC=='=')
                {
                        while(ColScan()==0);
                        break;
                }
        }
        return num;
}

