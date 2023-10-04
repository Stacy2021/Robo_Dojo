#include <Wire.h>
#include <AFMotor.h>

AF_DCMotor motor1(1); // Motor connected to M1
AF_DCMotor motor2(2); // Motor connected to M2

void setup() {
  Wire.begin(8); // 8 is the slave address
  Wire.onReceive(receiveEvent); // Register the receive event
  Serial.begin(9600);

  motor1.setSpeed(255); // Set motor speed (0-255)
  motor2.setSpeed(255);
}

void loop() {
  // Your slave code can continue running here
}

void receiveEvent(int byteCount) {
  while (Wire.available()) {
    String command = Wire.readStringUntil(':'); // Read the command from the master
    if (command == "SERVO_ANGLE") {
      int servoAngle = Wire.parseInt(); // Read the servo angle
      moveMotors(servoAngle); // Call a function to move the motors based on the servo angle
    }
  }
}

void moveMotors(int servoAngle) {
  // Map the servo angle to motor movement (adjust these values as needed)
  int motorSpeed = map(servoAngle, 0, 180, 0, 255);

  // Control the DC motors based on the servo angle
  if (servoAngle < 90) {
    // Turn left
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(motorSpeed);
    motor2.setSpeed(motorSpeed);
  } else if (servoAngle > 90) {
    // Turn right
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor1.setSpeed(motorSpeed);
    motor2.setSpeed(motorSpeed);
  } else {
    // Stop if the servo angle is 90 degrees
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
}
