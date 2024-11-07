// C++ code
//
#include <Servo.h>

int DISTANCIA = 0;

int NUMERO = 0;

Servo servo_3;

Servo servo_5;

Servo servo_6;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_3.attach(3, 500, 2500);
  servo_5.attach(5, 500, 2500);
  servo_6.attach(6, 500, 2500);
  Serial.begin(9600);
}

void loop()
{
  servo_3.write(0);
  servo_5.write(0);
  servo_6.write(0);
  DISTANCIA = 0.01723 * readUltrasonicDistance(9, 8);
  if (DISTANCIA > 20) {
    servo_3.write(0);
    servo_5.write(0);
    servo_6.write(0);
  } else {
    NUMERO = random(1, 3 + 1);
    Serial.println(NUMERO);
    if (NUMERO == 1) {
      servo_3.write(90);
      delay(1000); // Wait for 1000 millisecond(s)
      servo_3.write(0);
    }
    if (NUMERO == 2) {
      servo_5.write(90);
      delay(1000); // Wait for 1000 millisecond(s)
      servo_5.write(0);
    }
    if (NUMERO == 3) {
      servo_6.write(90);
      delay(1000); // Wait for 1000 millisecond(s)
      servo_6.write(0);
    }
    delay(3000); // Wait for 3000 millisecond(s)
  }
}