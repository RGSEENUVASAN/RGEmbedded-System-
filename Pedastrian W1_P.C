#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd(0x26, 16, 2); 

int redLed = 4;
int yellowLed = 9;
int greenLed = 10;
int button = 6;

int count = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(greenLed, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("Pedestrians:");
  lcd.setCursor(0, 1);
  lcd.print(count);
}

void loop() {
  if (digitalRead(button) == LOW) {
    count++;
    lcd.setCursor(0, 1);
    lcd.print("                "); // Clear line
    lcd.setCursor(0, 1);
    lcd.print(count);

    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(2000);

    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    delay(6000);

    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(2000);

    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
  }
}
