#include <Servo.h>

const int echoPin = 10;
const int echoPin2 = 5;
const int triggerPin = 9;
const int triggerPin2 = 6;

int distance, distance2;
long duration, duration2;

Servo myservo1;
Servo myservo;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin2, INPUT);
  myservo1.attach(3);
  myservo.attach(11);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if (distance < 40) {

    myservo1.write(0);
    delay(1000);
    myservo1.write(40);
    delay(5000);
  }
  digitalWrite(triggerPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  if (distance2 < 40) {
    myservo.write(30);
    delay(1000);
    myservo.write(0);
    delay(5000);
  }

}
