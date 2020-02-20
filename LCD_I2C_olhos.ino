//#include <LiquidCrystal_I2C.h>
#include <LCD_I2C_olhos.h>
//LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
LCD_I2C_olhos olhos();
byte um[8] = {
  B00001,
  B00011,
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte dois[8] = {
  B10000,
  B11000,
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111
};
byte tres[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00111,
  B00011,
  B00001
};
byte quatro[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100,
  B11000,
  B10000
};
byte f_sup[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};
byte f_inf[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup(){
  lcd.init(); // inicializa o LCD
  // Cria os caracteres compatíveis com o LCD
  lcd.createChar(0,um);
  lcd.createChar(1,dois);
  lcd.createChar(2,tres);
  lcd.createChar(3,quatro);
  lcd.createChar(4,f_sup);
  lcd.createChar(5,f_inf);
  lcd.backlight();
  
}


void loop(){
  piscar(5);  //pisca os olhos por 5 segundos
  
}

void piscar(int tempo){   //função para piscar a cada "tempo" segundos
  lcd.setCursor(4, 0);
  lcd.write(byte(0));
  lcd.setCursor(5, 0);
  lcd.write(byte(1));
  lcd.setCursor(10, 0);
  lcd.write(byte(0));
  lcd.setCursor(11, 0);
  lcd.write(byte(1));
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(5, 1);
  lcd.write(byte(3));
  lcd.setCursor(10, 1);
  lcd.write(byte(2));
  lcd.setCursor(11, 1);
  lcd.write(byte(3));
  
  delay(tempo * 1000);  
  lcd.setCursor(4, 0);
  lcd.write(byte(4));
  lcd.setCursor(5, 0);
  lcd.write(byte(4));
  lcd.setCursor(10, 0);
  lcd.write(byte(4));
  lcd.setCursor(11, 0);
  lcd.write(byte(4));
  lcd.setCursor(4, 1);
  lcd.write(byte(5));
  lcd.setCursor(5, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(11, 1);
  lcd.write(byte(5));
  delay(500);
}
