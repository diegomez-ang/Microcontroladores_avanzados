#include <16F877A.h>
#fuses HS, NOWDT, BROWNOUT, NOLVP
#use delay (clock = 4000000)
//#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
//#include <stdlib.h>
//#include <input.c>

#byte port_a= 5 
#byte port_b= 6 
#byte port_c= 7 
#byte port_d= 8

int count = 0;
//int i = 0;



void main()
{
   set_tris_d(0x00);
   port_d=(0x00);
   
   while(true){
      if(input(pin_a2)==0)
      {
         while(input(pin_a2)==0);
         count++;
                      
      }
      
      switch(count){
         case 1:
            output_c(0x0f);
            delay_ms(100);
            output_c(0xf0);
            delay_ms(100);
            break;
         case 2:
            output_c(0xcc);
            delay_ms(100);
            output_c(0x33);
            delay_ms(100);
            break;
         case 3:
            output_c(0x01);
            delay_ms(100);
            output_c(0x03);
            delay_ms(100);
            output_c(0x07);
            delay_ms(100);
            output_c(0x0f);
            delay_ms(100);
            output_c(0x1f);
            delay_ms(100);
            output_c(0x3f);
            delay_ms(100);
            output_c(0x7f);
            delay_ms(100);
            output_c(0xff);
            delay_ms(100);
            
            break;
         case 4:
            output_c(0x00);
            delay_ms(100);
            output_c(0xff);
            delay_ms(100);            
            break;
         case 5:
            count = 0;
            break;
         
      }
  
      
      
      
      /*
      if(count == 1){
         printf("Secuencia 1 ");
         
         //secuencia------
            
           for(i=0;i<3;i++){
            output_d(0x0f);
            delay_ms(1000);
            output_d(0xf0);
            delay_ms(1000);
           }
       
      }
      else if(count == 2){
         printf("Secuencia 2 ");
         
         // secuencia -------------
         for(i=0;i>3;i++){
            output_d(0xcc);
            delay_ms(1000);
            output_d(0x33);
            delay_ms(1000);
         }
         
      }
      else if(count == 3){
         printf("Secuencia 3 ");
            // secuencia ----------
         
      }
      else if(count == 4){
         printf("Secuencia 4 ");
         
      }
      else if(count == 5){
         count= 1;
      }   */ 
   }


}
