#include <16F877A.h>
#fuses HS, NOWDT, BROWNOUT, NOLVP
#use delay (clock = 4000000)

/*#byte trisa = 0x85
#byte porta = 0x05
#byte trisb = 0x86
#byte portb = 0x06*/

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#include <stdlib.h>
#include <input.c>

#byte port_a= 5 
#byte port_b= 6 
#byte port_c= 7 
#byte port_d= 8

int tiempo = 1000;
int contador = 0;


void main()
{

   bit_clear (port_b,0);
   bit_clear (port_b,0);
   
   set_tris_b(0x00);
   port_b=0x00;
   ///----- Pregunta por el pin
   while(true){
      if(input(pin_a1)==0)
      {
         while(input(pin_a1)==0);
         contador++;
         printf(" %d ", contador);
      }
      if(contador == 1){
         printf("Secuencia 1 ");
         secuencia_1();
      }
      else if(contador == 2){
         printf("Secuencia 2 ");
         secuencia_2();
      }
      else if(contador == 3){
         printf("Secuencia 3 ");
         secuencia_3();
      }
      else if(contador == 4){
         printf("Secuencia 4 ");
         secuencia_4();
      }
      else if(contador == 5){
         contador= 1;
      }    
   }
}



#include <16F877A.h>
#fuses HS, NOWDT, BROWNOUT, NOLVP
#use delay (clock = 4000000)

/*#byte trisa = 0x85
#byte porta = 0x05
#byte trisb = 0x86
#byte portb = 0x06*/

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#include <stdlib.h>
#include <input.c>

#byte port_a= 5 
#byte port_b= 6 
#byte port_c= 7 
#byte port_d= 8






int tiempo = 1000;
int contador = 0;

/* ------------------ SECUENCIA 1 ------------*/

void secuencia_1()
{
   output_b(0b01010101);
   delay_ms(tiempo);
   output_b(0b10101010);
   delay_ms(tiempo);
}

/* ------------------ SECUENCIA 2 ------------*/
void secuencia_2()
{
   output_b(0b00000000);
   delay_ms(tiempo);
   output_b(0b11111111);
   delay_ms(tiempo);
}
/* ------------------ SECUENCIA 3 ------------*/
void secuencia_3()
{ 
   output_b(0b10000001);
   delay_ms(tiempo);
   output_b(0b11000011);
   delay_ms(tiempo);
   output_b(0b11100111);
   delay_ms(tiempo);
   output_b(0b11111111);
   delay_ms(tiempo);
   output_b(0b11100111);
   delay_ms(tiempo);
   output_b(0b11000011);
   delay_ms(tiempo);
   output_b(0b10000001);
   delay_ms(tiempo);
}

/* ------------- SECUENCIA 4 ----------------*/
void secuencia_4()
{
   output_b(0b10000000);
   delay_ms(tiempo);
   output_b(0b01000000);
   delay_ms(tiempo);
   output_b(0b00100000);
   delay_ms(tiempo);
   output_b(0b00010000);
   delay_ms(tiempo);
   output_b(0b00001000);
   delay_ms(tiempo);
   output_b(0b00000100);
   delay_ms(tiempo);
   output_b(0b00000010);
   delay_ms(tiempo);
   output_b(0b00000001);
   delay_ms(tiempo);
   output_b(0b00000010);
   delay_ms(tiempo);
   output_b(0b00000100);
   delay_ms(tiempo);
   output_b(0b00001000);
   delay_ms(tiempo);
   output_b(0b00010000);
   delay_ms(tiempo);
   output_b(0b00100000);
   delay_ms(tiempo);
   output_b(0b01000000);
   delay_ms(tiempo);
   output_b(0b10000000);
   delay_ms(tiempo);
}

void main()
{

   bit_clear (port_b,0);
   bit_clear (port_b,0);
   
   set_tris_b(0x00);
   port_b=0x00;
   ///----- Pregunta por el pin
   while(true){
      if(input(pin_a1)==0)
      {
         while(input(pin_a1)==0);
         contador++;
         printf(" %d ", contador);
      }
      if(contador == 1){
         printf("Secuencia 1 ");
         secuencia_1();
      }
      else if(contador == 2){
         printf("Secuencia 2 ");
         secuencia_2();
      }
      else if(contador == 3){
         printf("Secuencia 3 ");
         secuencia_3();
      }
      else if(contador == 4){
         printf("Secuencia 4 ");
         secuencia_4();
      }
      else if(contador == 5){
         contador= 1;
      }    
   }
}




