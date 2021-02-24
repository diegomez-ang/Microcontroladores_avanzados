#include <16F877A.h>
#fuses HS, NOWDT, BROWNOUT, NOLVP
#use delay (clock = 4000000)
#byte port_c = 7
int i = 0;


void main()
{
   set_tris_c(0x00);
   port_c=(0x00);
   
   while (true)
   {
      for(i=0; i<5;i++)
      {
         ///secuencia 1
         for(i=0;i<2;i++)
         {
            output_c(0x0f);
            delay_ms(1000);
            output_c(0xf0);
            delay_ms(1000);
         }
         //secuencia 2 
         for(i=0;i<2;i++)
         {
            output_c(0xcc);
            delay_ms(1000);
            output_c(0x33);
            delay_ms(1000);
         }
         ///secuencia 3
         for(i=0;i<2;i++)
         {
            output_c(0x01);
            delay_ms(1000);
            output_c(0x03);
            delay_ms(1000);
            output_c(0x07);
            delay_ms(1000);
            output_c(0x0f);
            delay_ms(1000);
            output_c(0x1f);
            delay_ms(1000);
            output_c(0x3f);
            delay_ms(1000);
            output_c(0x7f);
            delay_ms(1000);
            output_c(0xff);
            delay_ms(1000);
         }
         //secuencia 4
         for(i=0; i<2;i++)
         {
            output_c(0x00);
            delay_ms(1000);
            output_c(0xff);
            delay_ms(1000);
         }         
      }
      
   }
}
