#define	AA_BIT 2
#define	SI_BIT 3
#define	STO_BIT 4
#define STA_BIT 5
#define	I2EN_BIT 6

//DEFINE FOR i2concclr sfr

#define	AAC_BIT 2
#define	SIC_BIT 3
#define	STAC_BIT 5
#define	I2ENC_BIT 6

#define	FOSC 12000000
#define	CCLK (FOSC*5)
#define	PCLK  (CCLK/4)
#define	 I2C_FREQ 100000
#define	 LOADVAL ((PCLK/I2C_FREQ)/2)