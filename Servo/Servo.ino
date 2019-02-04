#include<Servo.h>
Servo myServo;

int servo_pin = 7;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.write(90);
  Serial.println("90 deg");
}
