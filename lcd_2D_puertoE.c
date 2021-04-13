// Funciones definidas en esta en esta libreria, las cuales podemos llamar desde nuestro programa principal.

//  lcd_init()   Inicializaci�n del LCD (debe utilizarse al principio, antes de trabajar con el LCD).
//
//  lcd_putc(c)  Saca un caracters en el LCD.
//               Caracteres especiales de control:
//                      \f  Borrar LCD
//                      \n  Saltar a la segunda linea
//                      \b  Retroceder una posici�n.
//
//  lcd_gotoxy(x,y) Selecciona la nueva posicion de escritura en el LCD.
//                  (la esquina superior izquierda es 1,1)
//
//  lcd_getc(x,y)   Devuelve el caracter de la posicion x,y del LCD.


#bit  lcd_enable = 9.2
#bit  lcd_rw     = 9.1
#bit  lcd_rs     = 9.0
#byte lcd_a = 5
#byte lcd_b = 6

#define LCD_LINEA2 0x40    // Direccion de memoria para la segunda linea
#define LCD_DATO    1
#define LCD_COMANDO 0

#define LCD_CLEAR        0x01
#define LCD_HOME    0x02

#define LCD_DISPLAY_OFF  0x08
#define LCD_DISPLAY_ON   0x0C
#define LCD_CURSOR_ON    0x0E
#define LCD_CURSOR_BLINK 0x0F

#define LCD_CURSOR_SHIFT_RIGHT  0x10
#define LCD_CURSOR_SHIFT_LEFT   0x14
#define LCD_DISPLAY_SHIFT_RIGHT 0x18
#define LCD_DISPLAY_SHIFT_LEFT  0x1C


int lcd_leer()
{
  int valor;

  set_tris_e(0x10); //tenia un 18
  set_tris_b(0xFF);

  lcd_rw = 1;
  delay_cycles(1);
  lcd_enable = 1;
  delay_cycles(1);
  valor = lcd_b;
  lcd_enable = 0;
  delay_us(40);

  set_tris_b(0x00);
  return valor;
}


void lcd_enviar(int dir, int valor)
{
  set_tris_a(0x00);
  set_tris_b(0x00);

  lcd_rs = 0;
  while( bit_test(lcd_leer(),7) );
  lcd_rs = dir;
  delay_cycles(1);

  lcd_rw = 0;
  delay_cycles(1);
  lcd_enable = 0;
  lcd_b = valor;
  delay_cycles(1);
  lcd_enable = 1;
  delay_us(2);
  lcd_enable = 0;
  delay_us(40);
}


void lcd_init()
{
  int i;

  set_tris_a(0x18);
  set_tris_b(0x00);

  lcd_enable = 0;
  lcd_rw = 0;
  lcd_rs = 0;
  delay_ms(15);

  for(i=0; i<3; i++)
  {
    lcd_enviar(LCD_COMANDO,0x38);
    delay_ms(5);
  }
  lcd_enviar(LCD_COMANDO,LCD_DISPLAY_ON);
  lcd_enviar(LCD_COMANDO,0x06);
  lcd_enviar(LCD_COMANDO,LCD_CLEAR);
  lcd_enviar(LCD_COMANDO,LCD_HOME);
}


void lcd_gotoxy( byte x, byte y) {
   byte dir;

   if(y!=1)
     dir=LCD_LINEA2;
   else
     dir=0;
   dir+=x-1;
   lcd_enviar(LCD_COMANDO,0x80|dir);
}


void lcd_putc( char c) {
   switch (c) {
     case '\f'   : lcd_enviar(LCD_COMANDO,0x01);
                   delay_ms(2);
                   break;
     case '\n'   : lcd_gotoxy(1,2);               break;
     case '\b'   : lcd_enviar(LCD_COMANDO,0x10);  break;
     default     : lcd_enviar(LCD_DATO,c);        break;
   }
}


char lcd_getc( int x, int y) {
   char valor;

    lcd_gotoxy(x,y);

    lcd_rs = 1;
    valor = lcd_leer();
    lcd_rs = 0;

    return valor;
}
