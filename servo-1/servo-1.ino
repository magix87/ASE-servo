#include <Servo.h>

Servo myservo;  // utworzenie obiektu serwomechanizmu
int pos = 0;    // zmienna przechowująca pozycję serwomechanizmu

const int trigPin = 11;
const int echoPin = 10;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
  delay(100);
}

void loop() {
  // Wykonaj pomiar odległości
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance low: ");
  Serial.println(distance);  

  // Jeśli odległość jest mniejsza lub równa 50, poruszaj serwomechanizmem
  if (distance <= 50) {
    for (pos = 0; pos <= 190; pos += 1) {
      myservo.write(pos);
      delay(5);
    }
    for (pos = 190; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(5);
    }
  } else {
    // Jeżeli odległość jest większa niż 50, zatrzymaj serwomechanizm
    myservo.write(pos); // serwomechanizm pozostaje w obecnej pozycji
  }
}
