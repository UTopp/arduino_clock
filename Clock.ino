#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long tempo, ora, minuti, secondi;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Ora attuale");
  lcd.setCursor(14,0);

  pinMode(8, INPUT);
  pinMode(9, INPUT);
  
  ora = 0;
  minuti = 0;
  secondi = 0;
  tempo = 0;
}

void loop() {
  unsigned long ora_set = 1 * 60 * 60 * 1000;
  unsigned long minuti_set = 58 * 60 * 1000;


  // put your main code here, to run repeatedly:
  /*if(digitalRead(8) == HIGH)
    ora_set++;
  if(digitalRead(9) == HIGH)
    minuti_set++; */
  tempo = (unsigned long) ora_set + minuti_set + millis();
  ora =  tempo/(60 * 60 * 1000);
  minuti = (tempo - (ora*(60 * 60 * 1000)))/(60 * 1000);
  secondi = (tempo - (ora*(60 * 60 * 1000)) - (minuti*(60 * 1000)))/1000;

  lcd.setCursor(0, 1);
    lcd.print(secondi);
  /*if(ora>9){
    lcd.print(ora);
  } else {
    lcd.print("0");
    lcd.setCursor(1, 1);
    lcd.print(ora);
  }
  lcd.setCursor(2, 1);
  lcd.print(":");

  lcd.setCursor(3, 1);
  if(minuti>9){
    lcd.print(minuti);
  } else {
    lcd.print("0");
    lcd.setCursor(4, 1);
    lcd.print(minuti);
  }
  lcd.setCursor(5, 1);
  lcd.print(":");
  
  lcd.setCursor(6, 1);
  if(secondi>9){
    lcd.print(secondi);
  } else {
    lcd.print("0");
    lcd.setCursor(7, 1);
    lcd.print(secondi);
  }
  */

  delay(250);
  
}
