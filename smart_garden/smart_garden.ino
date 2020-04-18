#include  <LiquidCrystal.h>

// initialize the library with the numbers
//of the interface pins:
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);


const int dry = 700; // value for dry sensor
const int wet = 300; // value for wet sensor

void setup() {
  //Serial.begin(9600;)
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // clear the LCD screen:
  lcd.clear();


  lcd.setCursor(4, 0);
  lcd.print("Smart ");

  lcd.setCursor(4, 1);
  lcd.print("  garden s ");
  delay(100);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print(" Markom");

  lcd.setCursor(4, 1);
  lcd.print("   Dufalom");
  delay(100);
  lcd.clear();
}

void loop()
{
  lcd.clear();
  int sensorVal = analogRead(A0);

  // Sensor has a range of 239 to 595
  // We want to translate this to a scale or 0% to 100%
  // More info: https://www.arduino.cc/reference/en/language/functions/math/map/
  int percentageHumididy = map(sensorVal, wet, dry, 100, 0);

  lcd.print(percentageHumididy);
  lcd.println("%");
  //lcd.print(sensorVal);


  delay(100);
}
