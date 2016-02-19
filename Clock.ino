#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long tot_time, hour, minute, second;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Current Time :");
  lcd.setCursor(14,0);

  pinMode(8, INPUT);        // pins used for manual settings
  pinMode(9, INPUT);        // ***
  
  hour = 0;
  minute = 0;
  second = 0;
  tot_time = 0;
}

void loop() {
  unsigned long hour_set = 1 * 60 * 60 * 1000;
  unsigned long minute_set = 58 * 60 * 1000;


  // put your main code here, to run repeatedly:
  if(digitalRead(8) == HIGH)                                  //used to change the time without needing to access the code later on
    hour_set++;
  if(digitalRead(9) == HIGH)                                  //same as above
    minute_set++; 
  tot_time = hour_set + minute_set + millis();                //actual time considering manual settings
  hour =  tot_time/(60 * 60 * 1000);                                              // *** THIS PART OF THE CODE SEEMS NOT TO WORK ***
  minute = (tot_time - (hour*(60 * 60 * 1000)))/(60 * 1000);                      // *** THIS PART OF THE CODE SEEMS NOT TO WORK ***
  second = (tot_time - (hour*(60 * 60 * 1000)) - (minute*(60 * 1000)))/1000;      // *** THIS PART OF THE CODE SEEMS NOT TO WORK ***

  lcd.setCursor(0, 1);                //fixes overlapping digits
    lcd.print(second);
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
  
  delay(250);                       // intendet to limit amount of data sent to the display
}
