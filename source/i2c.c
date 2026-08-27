#include<lpc21xx.h>
#include"types.h"
#include"i2c.h"
#include"i2c_define.h"
void i2c_init(void)
{
//cfg req gpio pins as scl&sda pins
PINSEL0|=0X00000050;
//ENABLE I2C PERIPHERALS
I2CONSET=1<<I2EN_BIT;
//CFG I2C SPEED/FREQ
I2SCLH=I2SCLL=LOADVAL;
}


void i2c_start(void)
{
//cfg to issue start bit /cond/event
I2CONSET=1<<STA_BIT;
//WAIT FOR START EVENT COMPLETION/STATUS
while(((I2CONSET>>SI_BIT)&1)==0);
//clear start event /bit
I2CONCLR=1<<STAC_BIT;
}


void i2c_stop(void)
{
//cfg to isuue stop bit /cond/event
I2CONSET=1<<STO_BIT;
I2CONCLR=1<<SIC_BIT;
}

 void i2c_restart(void)
 {
 //cfg to issue restart bit/cond/event
 I2CONSET=1<<STA_BIT;
 //TRIGGER RESTART EVENT
 I2CONCLR=1<<SIC_BIT;
 //WAIT FOR RESTART EVENT COMPILATION /STATAS
 while(((I2CONSET>>SI_BIT)&1)==0);
 //CLEAR START EVENT/BIT
 I2CONCLR=1<<STAC_BIT;
 }


void i2c_write(u8 sByte)
{
//place byte to be transmitted in tx/rx buffer
I2DAT=sByte;
//trigger transmission of byte
I2CONCLR=1<<SIC_BIT;
//WAIT FOR BYTE TRANSMISSION COMPLETIOM/STATUS
while(((I2CONSET>>SI_BIT)&1)==0);
}

u8 i2c_nack(void)
{
//trigger reception of byte
I2CONCLR=1<<SIC_BIT;
//WAIT UNTIL BYTE RECEIVED COMPLETION|STATUS
while(((I2CONSET>>SIC_BIT)&1)==0);
//AUTOMATICALLY ISSUES NACK
//READ RECEVED BYTE
return I2DAT;
}

u8 i2c_mack(void)
{
I2CONSET=1<<AA_BIT;
//TRIGGER RECEPTIOMof byte
I2CONCLR=1<<SIC_BIT;
//WAIT UNTILL BYTE received completion|stutas
while(((I2CONSET>>SIC_BIT)&1)==0);
//AUTOMATICALLY ISSUES MACK
//CLEAR aa_bit
I2CONCLR=1<<AA_BIT;
//read recvd byte
return I2DAT;
}
