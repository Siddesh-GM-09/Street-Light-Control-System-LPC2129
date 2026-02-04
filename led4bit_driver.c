#include<lpc21xx.h>
#include "header.h"
//Write Data to LCD
void lcd_data(unsigned char data){
	unsigned int temp;
	//Higher Bits
	IOCLR1=0XFE<<16;
	temp=(data&0XF0)<<16;
	IOSET1=temp;
	IOSET1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
	
	//Lower Bits
	IOCLR1=0XFE<<16;
	temp=(data&0X0F)<<20;
	IOSET1=temp;
	IOSET1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
}
//Write Command to LCD
void lcd_cmd(unsigned char cmd){
	unsigned int temp;
	//Higher Bits
	IOCLR1=0XFE<<16;
	temp=(cmd&0XF0)<<16;
	IOSET1=temp;
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
	//Lower Bits
	IOCLR1=0XFE<<16;
	temp=(cmd&0X0F)<<20;
	IOSET1=temp;
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
}
//LCD 4-Bit Initialization
void lcd_init(){
	IODIR1=0XFE<<16;
	lcd_cmd(0X02);
	lcd_cmd(0X03);
	lcd_cmd(0X28);
	lcd_cmd(0X0E);
	lcd_cmd(0X01);
}
//String printing
void lcd_string(char *ptr){
	while(*ptr!='\0'){
		lcd_data(*ptr);
		ptr++;
	}
}
//Integer 
void lcd_integer(int num){
	int arr[10],i=0;
	if(num==0){
		lcd_data('0');
	}
	if(num<0){
		lcd_data('-');
		num=-num;
	}
	while(num){
		arr[i]=(num%10)+48;
		num/=10;
		i++;
	}
	for(i=i-1;i>=0;i--){
		lcd_data(arr[i]);
	}
}
void lcd_float(float f){
	int num;
	if(f<0){
		lcd_data('-');
		f=-f;
	}
	if(f==0){
		lcd_string("0.0");
		return;
	}
	num=f;
	lcd_integer(num);
	lcd_data('.');
	num=(f-num)*1000000;
	lcd_integer(num);
}
