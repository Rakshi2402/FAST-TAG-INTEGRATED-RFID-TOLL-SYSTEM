#include<lpc21xx.h>
#include"dummy_fun.h"
//#include"my_define.h"
 #include"lcd.h"
#include"define.h"
#include"delay.h"
#include"types.h"
#include"i2c.h"
#include"lcd_define.h"
#include"i2c_define.h"
#include"i2c_eeprom.h"
#include"adc_define.h"
#include"kpm_define.h"
#include"dummy_fun.h"
 char tag_no[3][10]={{"12623314"},{"12535708"},{"12546806"}}; 

char vehicle_number[3][10]={{"3244"},{"5776"},{"3456"}}; 

char bal[3][4]={"100","200","300"}; 
char tag_buff[10];
char vech_buff[5],bal_buff[4];
extern int i;
int amount;
//extern volatile char e0_flag,e1_flag;

int main()
{
	 init_fun();
	 /*initLCD();
	 InitUART0();
	 i2c_init();
	 Init_ADC();
	 Init_KPM(); */
	 save_cards();
	   cmdLCD(0X01);
	   while(1)
	   {
	   
	   	process_sensor();
		
		


	   }	
}

