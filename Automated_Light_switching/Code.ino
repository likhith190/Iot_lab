int sensorPin = A0;
int sensorValue = 0;
int light=0;
void setup() {
Serial.begin(9600);
pinMode(5,OUTPUT);
}
void loop() {
sensorValue = analogRead(sensorPin);
light = map(sensorValue,6,679,0,255);Serial.println(light);
if(light < 200){
analogWrite(5,255-light);
}else{
analogWrite(5,0);
}
delay(100);
}
