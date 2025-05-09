#include <AFMotor.h>  // Motor shield library
#include <Servo.h>    // Servo motor library (still included, but we won't use it)
#include <NewPing.h>  // Ultrasonic library (still included, but we won't use it)

const int sensorPin1 = A0;  // First IR sensor (TCRT5000)
const int sensorPin2 = A1;  // Second IR sensor (TCRT5000)

const int Max_Speed = 150;

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int sensorValue1 = 0;
int sensorValue2 = 0;
int speedSet = 0;
boolean goesForward = false;

void setup() {
  Serial.begin(9600);
  
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);

  moveForward();  // Start by moving forward
}

void loop() {
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);

  Serial.print("Sensor1: ");
  Serial.print(sensorValue1);
  Serial.print(" | Sensor2: ");
  Serial.println(sensorValue2);

  int threshold = 300;  // Adjust based on your surface

  if (sensorValue1 > threshold && sensorValue2 > threshold) {
    moveForward();
  } else {
    moveStop();
    delay(100);
    moveBackward();
    delay(400);
    moveStop();
    delay(100);
    turnLeft();
    moveStop();
    delay(100);
  }
}

void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    
    for (speedSet = 0; speedSet < Max_Speed; speedSet += 2) {
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      motor3.setSpeed(speedSet);
      motor4.setSpeed(speedSet);
      delay(5);
    }
  }
}

void moveBackward() {
  goesForward = false;
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  
  for (speedSet = 0; speedSet < Max_Speed; speedSet += 2) {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(400);  // Turn time (adjust as needed)
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
