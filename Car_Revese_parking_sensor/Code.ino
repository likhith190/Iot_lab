const int trigPin = 11;const int echoPin = 10;
const int buzzPin = 4;
//const int led = 2;
int duration;
float distance;
void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzPin, OUTPUT);
//pinMode(led, OUTPUT);
}
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = 0.034*(duration/2);
if (distance < 100)
{
digitalWrite(buzzPin,HIGH);
//digitalWrite(led,HIGH);
}
else
{
digitalWrite(buzzPin,LOW);
//digitalWrite(led,LOW);
}
delay(300);
}
