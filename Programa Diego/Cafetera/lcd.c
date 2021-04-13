 #include <16f877a.h>
#fuses XT, NOPROTECT, NOWRT, NOPUT, NOWDT, NOLVP, NOCPD 
#use delay (clock=4000000)
#include <lcd_2.c>  // Librer�a para el manejo del lcd  
#include <kbd_2D.c>
#byte port_a=5
#byte port_b=6
#byte port_c=7
#byte port_d=8

char k;


void menu(){  //// Menu principal
      lcd_gotoxy(3,1);
      lcd_putc("ELIJA UNA OPCION");
      lcd_gotoxy(1,2);
      lcd_putc("1-Tinto");
      lcd_gotoxy(10,2);
      lcd_putc("4-Capuchino");
      lcd_gotoxy(21,1);
      lcd_putc("2-Agua");
      lcd_gotoxy(30,1);
      lcd_putc("5-Expreso");
      lcd_gotoxy(30,2);
      lcd_putc("6-Americano");
      lcd_gotoxy(21,2);
      lcd_putc("3-Te");
      }
void tinto(){   ///  PREPARAR TINTO  -----------
      lcd_putc("\f");
      for(int i = 0 ; i<10; i ++){
         lcd_gotoxy(3,2);
         lcd_putc("Preparando tinto");
         delay_ms(200);
         lcd_gotoxy(3,2);
         lcd_putc("\f");  
         delay_ms(200);
      }
         lcd_putc("\f");
         lcd_gotoxy(3,2);
         lcd_putc("RETIRE LA BEBIDA");
         delay_ms(1000);
         lcd_putc("\f");
      menu();  
      }
void agua(){   ///  SIRVIENDO AGUA  -----------
      lcd_putc("\f");
      for(int i = 0 ; i<10; i ++){
         lcd_gotoxy(3,2);
         lcd_putc("Sirviendo agua");
         delay_ms(200);
         lcd_gotoxy(3,2);
         lcd_putc("\f");  
         delay_ms(200);
      }
         lcd_putc("\f");
         lcd_gotoxy(3,2);
         lcd_putc("RETIRE LA BEBIDA");
         delay_ms(1000);
         lcd_putc("\f");
      menu();  
      }
void te(){   ///  PREPARAR TE  -----------
      lcd_putc("\f");
      for(int i = 0 ; i<10; i ++){
         lcd_gotoxy(3,2);
         lcd_putc("Preparando te");
         delay_ms(200);
         lcd_gotoxy(3,2);
         lcd_putc("\f");  
         delay_ms(200);
      }
         lcd_putc("\f");
         lcd_gotoxy(3,2);
         lcd_putc("RETIRE LA BEBIDA");
         delay_ms(1000);
         lcd_putc("\f");
      menu();  
      }
void capuchino(){   ///  PREPARAR CAPUCHINO  -----------
      lcd_putc("\f");
      for(int i = 0 ; i<10; i ++){
         lcd_gotoxy(1,2);
         lcd_putc("Preparando capuchino");
         delay_ms(200);
         lcd_gotoxy(1,2);
         lcd_putc("\f");  
         delay_ms(200);
      }
         lcd_putc("\f");
         lcd_gotoxy(3,2);
         lcd_putc("RETIRE LA BEBIDA");
         delay_ms(1000);
         lcd_putc("\f");
      menu();  
      }
void expreso(){   ///  PREPARAR EXPRESO  -----------
      lcd_putc("\f");
      for(int i = 0 ; i<10; i ++){
         lcd_gotoxy(2,2);
         lcd_putc("Preparando expreso");
         delay_ms(200);
         lcd_gotoxy(2,2);
         lcd_putc("\f");  
         delay_ms(200);
      }
         lcd_putc("\f");
         lcd_gotoxy(3,2);
         lcd_putc("RETIRE LA BEBIDA");
         delay_ms(1000);
         lcd_putc("\f");
      menu();  
      }
void americano(){   ///  PREPARAR AMERICANO  -----------
      lcd_putc("\f");
      for(int i = 0 ; i<10; i ++){
         lcd_gotoxy(1,2);
         lcd_putc("Preparando americano");
         delay_ms(200);
         lcd_gotoxy(1,2);
         lcd_putc("\f");  
         delay_ms(200);
      }
         lcd_putc("\f");
         lcd_gotoxy(3,2);
         lcd_putc("RETIRE LA BEBIDA");
         delay_ms(1000);
         lcd_putc("\f");
      menu();  
      }

void main(void)
{

   /*int i = 0;
   int contador = 0;
 */
   lcd_init(); //inicializa lcd 

   while(TRUE){ 
   
      
      k=kbd_getc();
      if(k!=0){
         if(k == '0'){
            menu();
            }
         if(k == '1'){  
            tinto();            
            }
         if(k == '2'){  
            agua();            
            }
         if(k == '3'){  
            te();            
            }
         if(k == '4'){  
            capuchino();            
            }
         if(k == '5'){  
            expreso();            
            }
         if(k == '6'){  
            americano();            
            }
      }
      
      
}
}
    

