#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define smoke_pin A1
#define green_led 0
#define red_led 1
#define buzz_pin 1
void setup()
{
pinMode(green_led, OUTPUT);
pinMode(red_led, OUTPUT);
lcd.begin(16, 2);
}
void loop()
{
int value = map(analogRead(smoke_pin), 300, 750, 0, 100);
Serial.println(value);
if(value >10){
digitalWrite(green_led,LOW);
digitalWrite(red_led,HIGH);
lcd.setCursor(0,0);
lcd.print("DANGER!!!");
}
else{
digitalWrite(green_led,HIGH);
digitalWrite(red_led,LOW);
lcd.setCursor(0,0);
lcd.setCursor(0,0);
lcd.print("SAFE......");
}
}
