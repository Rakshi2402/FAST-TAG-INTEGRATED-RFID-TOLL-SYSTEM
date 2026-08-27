#include"types.h"
#include"i2c_define.h"
#include"i2c.h"
#include"delay.h"
void i2c_eeprom_bytewrite(u8 SlaveAddr,u16 wBuffAddr,u8 sByte)
{
i2c_start(); //start
i2c_write(SlaveAddr<<1); //sa+w1 &get ack
i2c_write(wBuffAddr>>8); //wbuffAddr, &get ack
i2c_write(wBuffAddr);
i2c_write(sByte); //sbyte, &get ack
i2c_stop();
delay_ms(10);
}

u8 i2c_eeprom_randomread(u8 SlaveAddr,u16 rBuffAddr) 
{
u8 rByte;
i2c_start();  //start
i2c_write(SlaveAddr<<1); //sa + w1 & grt ack;
i2c_write(rBuffAddr>>8); //wbuffAddr, &get ack
i2c_write(rBuffAddr); //rbuffaddr, &get ack
i2c_restart();
//i2c_write(rBuffAddr); //rBuffAddr, & get acck
//i2c_restart();
i2c_write((SlaveAddr<<1)|1); //sa+ R ,&get ack
rByte=i2c_nack(); //read byute &buff nack
i2c_stop();
return rByte;
}


void i2c_eeprom_pagewrite(u8 SlaveAddr,u16 wBuffstartAddr,u8* ptr8Bytes, int nBytes)
{
u32 i;
i2c_start(); //start
i2c_write(SlaveAddr<<1);	//sa+w.&get ack
i2c_write(wBuffstartAddr>>8); //wbuffAddr, &get ack
i2c_write(wBuffstartAddr);	 //wbuffstartaddr,&get ack
for(i=0;i<nBytes;i++)
{
//send one byte at5 atime,get ack
i2c_write(ptr8Bytes[i]);
}
i2c_stop();		
delay_ms(10);
}
void i2c_eeprom_seqread(u8 SlaveAddr,u16 rBuffstartAddr,u8 *ptr8Bytes,int nBytes)
{
u32 i;
i2c_start();  //start
i2c_write(SlaveAddr<<1);
i2c_write(rBuffstartAddr>>8); //rbuffAddr, &get ack
i2c_write(rBuffstartAddr);
i2c_restart();
i2c_write((SlaveAddr<<1)|1);
for(i=0;i<(nBytes-1);i++)
{
//read byte & give mack
ptr8Bytes[i]=i2c_mack();
}
//read last byte &give nack
ptr8Bytes[i]=i2c_nack(); 
i2c_stop();
ptr8Bytes[i+1]='\0';
}
