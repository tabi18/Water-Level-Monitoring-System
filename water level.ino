#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
   lcd.begin();
   lcd.backlight();
}

void loop() {
  unsigned int value=analogRead(A0);
  double percentage=(value*100)/380;
  Serial.println(value);
  lcd.clear();
  if(value<220){
    lcd.print("LOW WATER LEVEL!");
    lcd.setCursor(0, 1);
    lcd.print(percentage);
    lcd.print("%");
    tone(8,440);
    delay(500);
    noTone(8);
    delay(500);
    }
    else{
      lcd.clear();
      lcd.print("HIGH WATER LEVEL!");
      lcd.setCursor(0, 1);
      lcd.print(percentage);
      lcd.print("%");
    }

  delay(1000);
}
