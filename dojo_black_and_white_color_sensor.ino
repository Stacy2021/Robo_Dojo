// Define color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Variables for Color Pulse Width Measurements
int blackPW = 0;
int whitePW = 0;

void setup() {
  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Set Pulse Width scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Set Sensor output as input
  pinMode(sensorOut, INPUT);

  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read Black Pulse Width
  blackPW = getBlackPW();
  // Delay to stabilize sensor
  delay(200);

  // Read White Pulse Width
  whitePW = getWhitePW();
  // Delay to stabilize sensor
  delay(200);

  // Print output to Serial Monitor
  Serial.print("Black PW = ");
  Serial.print(blackPW);
  Serial.print(" - White PW = ");
  Serial.println(whitePW);
}

// Function to read Black Pulse Width
int getBlackPW() {
  // Set sensor to read Black only
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read White Pulse Width
int getWhitePW() {
  // Set sensor to read White only
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}
