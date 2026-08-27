void delay_us(unsigned int dlyus)
{
for(dlyus*=12;dlyus>0;dlyus--);
}
void delay_ms(unsigned int dlyms)
{
for (dlyms*=12000;dlyms>0;dlyms--);
}
void delay_s(unsigned int delays)
{
for(delays*=12000000;delays>0;delays--);
}

