#include <16f877a.h>
#include <lcd_2D.c>  // Librer�a para el manejo del lcd 
#include <kbd_2D.c>
#FUSES NOWDT, XT, NOPUT, NOPROTECT, NOBROWNOUT, NOLVP, NOCPD, NOWRT, NODEBUG
#use delay (clock=4000000)


//Definir tama�o de la variable


void main(void){
   while(true){
   lcd_init();
   lcd_gotoxy(1,1);
   lcd_putc("PROBANDO LCD");
   lcd_gotoxy(1,2);
   lcd_putc("DIEGO ALEJANDRO");
   lcd_gotoxy(21,1);
   lcd_putc("GOMEZ ANGARITA");
   lcd_gotoxy(21,2);
   lcd_putc("12345678910125489632");


}

}

