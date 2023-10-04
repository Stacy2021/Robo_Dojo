#include <Wire.h>
#include <Servo.h>

Servo servo1;

void setup() {
  Wire.begin(); // Initialize I2C communication
  Serial.begin(9600);
  servo1.attach(9); // Attach servo to pin 9
}

void loop() {
  int servoAngle = servo1.read(); // Read the current angle of the servo

  // Send the servo angle as a command to the slave Arduino
  Wire.beginTransmission(8); // 8 is the slave address (change it accordingly)
  Wire.write("SERVO_ANGLE:");
  Wire.write(servoAngle);
  Wire.endTransmission();

  delay(1000); // Wait for a second
}
