#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long tot_time_sec, hour, minute, second;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Current Time :");

  pinMode(8, INPUT);        // pins used for manual settings
  pinMode(9, INPUT);        // ***
}

void loop() {
  // put your main code here, to run repeatedly:
  tot_time_sec = millis()/1000;                         //time in seconds
  hour =  tot_time_sec / (60*60);
  minute = (tot_time_sec % (60*60)) / (60);
  second = (tot_time_sec % (60*60)) % (60);

  lcd.setCursor(0, 1);                                  //fixes overlapping digits
    lcd.print(hour);
  if(hour>9){
    lcd.print(hour);
  } else {
    lcd.print("0");
    lcd.setCursor(1, 1);
    lcd.print(hour);
  }
  lcd.setCursor(2, 1);
  lcd.print(":");

  lcd.setCursor(3, 1);
  if(minute>9){
    lcd.print(minute);
  } else {
    lcd.print("0");
    lcd.setCursor(4, 1);
    lcd.print(minute);
  }
  lcd.setCursor(5, 1);
  lcd.print(":");
  
  lcd.setCursor(6, 1);
  if(second>9){
    lcd.print(second);
  } else {
    lcd.print("0");
    lcd.setCursor(7, 1);
    lcd.print(second);
  }                                 // end of overlapping digits fix
  
}
