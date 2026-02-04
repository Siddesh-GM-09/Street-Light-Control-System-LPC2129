#include<lpc21xx.h>
#include "header.h"
unsigned int temp[10],volt[10],ints[10],val=0,tsum=0,vints=0;
float Vout=0,Temp=0;
float Intensity=0.0;
int i=0;
//Potentiometer Reading 
void Potentiometer(void){
		val=0;
		for(i=0;i<10;i++){
			volt[i]=mcp3204_adc_read(1); //Channel
			val=val+volt[i];
			delay_ms(15);
		}
		val=val/10;
		Vout=(val*3.3)/4095;
		lcd_cmd(0X80);
		lcd_float(Vout);
		lcd_data('V');
		uart0_tx_string("\r\nVolt : ");
		uart0_tx_float(Vout);
		uart0_tx_string("\r\n");
}
//Temperature Reading 
void Temperature(void){
		tsum=0;
		for(i=0;i<10;i++){
			temp[i]=mcp3204_adc_read(2);//Channel
			tsum=tsum+temp[i];
			delay_ms(15);
		}
		tsum=tsum/10;
		Vout=(tsum*3.3)/4095;
		Temp=(Vout-0.05)/0.01;
		lcd_cmd(0XC0);
		lcd_float(Temp);
		lcd_data('C');
		uart0_tx_string("\r\nTemp : ");
		uart0_tx_float(Temp);
		uart0_tx_string("\r\n");
}
//LDR Reading
void LDR(void){
		vints=0;
		for(i=0;i<10;i++){
			ints[i]=mcp3204_adc_read(3);//Channel
			vints=vints+ints[i];
			delay_ms(15);
		}
		vints=vints/10;
		Intensity=(vints/4095.0f)*100.0f;
		//lcd_cmd(0X80);
		//lcd_float(Intensity);
		//lcd_data('%');
		uart0_tx_string("\r\nIntensity : ");
		uart0_tx_float(Intensity);
		uart0_tx_string("%\r\n");
}
