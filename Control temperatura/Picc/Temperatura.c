#include <16f877a.h>
#device adc = 10 //crea conversor 
#fuses XT, NOWDT
#use delay (clock=4000000)//cristal
#include <stdlib.h>
#include <lcd_2D_puertoE.c>  // Librer�a para el manejo del lcd  1024 posiciones 
#include <kbd_2D.c>
#byte port_a=5
#byte port_b=6
#byte port_c=7
#byte port_d=8

int16 conv_1, conv_2, conv_3; //captura el valor del conversor
float volt_1, volt_2, volt_3;
int16 temp_1, temp_2, temp_3;

void show_temp(){
   set_adc_channel(0);     //habilita la salida 0 como lector
   delay_us(20);           //espera
   conv_1 = read_adc();    //conv_1 va a ser igual al valor del adc
   volt_1 = (5.0 * conv_1)/1024.0;
   temp_1 = volt_1*100;
   
   set_adc_channel(1);
   delay_us(20);
   conv_2 = read_adc();
   volt_2 = (5.0*conv_2)/1024.0;
   temp_2 = volt_2*100;
   
   set_adc_channel(2);
   delay_us(20);
   conv_3 = read_adc();
   volt_3 = (5.0*conv_3)/1024.0;
   temp_3 = volt_3*100;
   
   /*----- -- IMPRESION DE PANTALLA ---------- */
       lcd_gotoxy(3,1);
       lcd_putc("T-1    T-2    T-3");
       lcd_gotoxy(1,2);
       printf(lcd_putc,"C:%Ld   C:%Ld   C:%Ld",conv_1,conv_2,conv_3);
       lcd_gotoxy(21,1);
       printf(lcd_putc,"V:%f V:%f V:%f",volt_1,volt_2,volt_3);
       lcd_gotoxy(21,2);
       printf(lcd_putc,"T:%Ld   T:%Ld   T:%Ld",temp_1,temp_2,temp_3);
}


      
      
void main(void)
{
   setup_adc_ports(RA0_RA1_RA3_ANALOG); //DEFINO LOS PUERTOS A UTILIZAR
   setup_adc(ADC_CLOCK_INTERNAL);
   
   lcd_init(); //inicializa lcd 
   while(TRUE){   
    //  test();
      show_temp();
      delay_ms(100);
      
     
     }
}
