//ER3N

#include "NewPing.h"
#include <LiquidCrystal_I2C.h>
#define ECHO_PIN 7
#define TRIG_PIN 6
#define MAX_UZAKLIK 400

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_UZAKLIK);
LiquidCrystal_I2C lcd(0x27,16,2);

float mesafe,boy;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  mesafe = sonar.ping_cm();
  boy = 200 - mesafe;
  lcd.setCursor(0,0);
  lcd.print("|-BOYUNUZ-|");
  lcd.setCursor(0,1);
  lcd.print(boy);
  delay(200);
  lcd.clear();
}
