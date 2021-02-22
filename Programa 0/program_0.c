#include <16F877A.h>
#fuses HS, NOWDT, BROWNOUT, NOLVP
#use delay (clock = 4000000)
#byte port_a = 5   // renombrando el puerto 
#byte port_b = 6   // renombrando el puerto 
#byte port_c = 7   // renombrando el puerto 
#byte port_d = 8   // renombrando el puerto 
#byte port_c = 9   // renombrando el puerto 


void main()
{
   set_tris_b(0x00);
   port_b=(0x00);
   
   while(true)
   {
      output_high(pin_B0);
      delay_ms(100);
      output_low(pin_B0);
      delay_ms(100);
   }
   

}

