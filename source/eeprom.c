#include"i2c.h"
#include"i2c_eeprom.h"
#include"lcd.h"
#include"delay.h"
#include "string.h"
#include<stdlib.h>
#include"my_define.h"

extern char tag_no[3][10];
extern char vehicle_number[3][10];
extern char bal[3][4];
extern char tag_buff[10];
extern char vech_buff[5],bal_buff[4];
extern int i,amount;
/*char tag_no[3][10]={{"12531874"},{"12556052"},{"12553458"}}; 

char vehicle_number[3][10]={{"32445"},{"5776"},{"3456"}}; 

char bal[3][4]={"100","200","300"}; 
char tag_buff[10];
char vech_buff[5],bal_buff[4];
int i,amount;*/
/*
int main()
{
	initLCD();
	i2c_init();
	cmdLCD(0x01);
		cmdLCD(0x80);
		strLCD("hello");
		delay_ms(3000);
		cmdLCD(0x01);*/	
void save_cards()
{
	for(i=0;i<3;i++)
	{
		i2c_eeprom_pagewrite(SLAVE_ADDR,(ID_ADDR+i*10),(u8*)tag_no[i],10);
		//delay_ms(100);		
	}
	/*
	for(i=0;i<3;i++)
	{
		i2c_eeprom_seqread(SLAVE_ADDR,(ID_ADDR+i*10),(u8*)tag_buff,10);
	//	delay_ms(100);
		cmdLCD(0x01);
		cmdLCD(0x80);
		strLCD(tag_buff);	
		delay_ms(3000);
		cmdLCD(0x01);
	} */
	for(i=0;i<3;i++)
	{	
		i2c_eeprom_pagewrite(SLAVE_ADDR,(VECH_ADDR+i*5),(u8*)vehicle_number[i],5);
		//delay_ms(100);		
	}
	/*for(i=0;i<3;i++)
	{
		i2c_eeprom_seqread(SLAVE_ADDR,(VECH_ADDR+i*5),(u8*)vech_buff,5);
	//	delay_ms(100);
		cmdLCD(0x01);
		cmdLCD(0x80);
		strLCD(vech_buff);
		delay_ms(3000);
		cmdLCD(0x01);
	}  */
	for(i=0;i<3;i++)
	{
		i2c_eeprom_pagewrite(SLAVE_ADDR,(BAL_ADDR+i*4),(u8*)bal[i],4);
		//delay_ms(100);
	}
/*	for(i=0;i<3;i++)
	{
		i2c_eeprom_seqread(SLAVE_ADDR,(BAL_ADDR+i*4),(u8*)bal_buff,4);
	//	delay_ms(100);
		cmdLCD(0x01);
		cmdLCD(0xc0);
		amount=atoi(bal_buff);
		u32LCD(amount);
		delay_ms(3000);
		cmdLCD(0x01);
	}*/
}
