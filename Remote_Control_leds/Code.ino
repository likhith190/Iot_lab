#include <IRremote.h>
int reciever= 12;int red = 11;
int green=9;
int yellow=6;
int blue=3;
IRrecv irrecv(reciever);
decode_results results;
void setup()
{
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(blue, OUTPUT);
Serial.begin(9600);
irrecv.enableIRIn(); // Start the receiver
}
void loop()
{
if (irrecv.decode(&results)) {
Serial.println(results.value, HEX);
irrecv.resume(); // Receive the next value
if(results.value==0xFD08F7){
digitalWrite(red,HIGH);
digitalWrite(green,LOW);
digitalWrite(yellow,LOW);
digitalWrite(blue,LOW);
}
else if(results.value==0xFD8877){
digitalWrite(red,LOW);
digitalWrite(green,HIGH);
digitalWrite(yellow,LOW);
digitalWrite(blue,LOW);
}
else if(results.value==0xFD48B7){
digitalWrite(red,LOW);
digitalWrite(green,LOW);
digitalWrite(yellow,HIGH);
digitalWrite(blue,LOW);
}else if(results.value==0xFD28D7){
digitalWrite(red,LOW);
digitalWrite(green,LOW);
digitalWrite(yellow,LOW);
digitalWrite(blue,HIGH);
}
else if(results.value==0xFD00FF){
digitalWrite(red,LOW);
digitalWrite(green,LOW);
digitalWrite(yellow,LOW);
digitalWrite(blue,LOW);
}
}
delay(100);
}
