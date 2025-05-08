#include <Servo.h>       // library for servo motor
#include <AFMotor.h>     // library for motor shield

// ultrasonic sensor
const int Trig_Pin = A4;
const int Echo_Pin = A5;
// max speed and distance detection
const int Max_Speed = 200;
const int Max_Dist = 250;

// cleaning robot
const int ClearRobot = 11;

// IR sensor
const int Pir_1 = 2;
const int Pir_2 = 3;

// servo
Servo myservo;

// motor
AF_DCMotor motorLeft1(1); // 假设左电机 1 连接到 M1
AF_DCMotor motorLeft2(2); // 假设左电机 2 连接到 M2
AF_DCMotor motorRight1(3); // 假设右电机 1 连接到 M3
AF_DCMotor motorRight2(4); // 假设右电机 2 连接到 M4

int distance = 250;
int speedSet = 0;
boolean goesForward = false;

// record turning direction
boolean turnedLeft = false;
boolean turnedRight = false;

void setup() {
  // 初始化串口通信
  Serial.begin(9600);
  // initiate servo
  myservo.attach(10);
  myservo.write(90);  // 初始位置为中间
  // 设置引脚模式
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  pinMode(ClearRobot, OUTPUT);
  pinMode(Pir_1, INPUT);
  pinMode(Pir_2, INPUT);
  // 启动清洁吸尘器
  digitalWrite(ClearRobot, HIGH);

  // set motor speed
  motorLeft1.setSpeed(Max_Speed);
  motorLeft2.setSpeed(Max_Speed);
  motorRight1.setSpeed(Max_Speed);
  motorRight2.setSpeed(Max_Speed);
}

void loop() 
{
  // edge detection
    int edgeLeft = digitalRead(Pir_1);
    int edgeRight = digitalRead(Pir_2);
    if (edgeLeft == LOW || edgeRight == LOW) {
        // detect edge, turn around
        turnAround();
    } else {
        // detect obstacle
        checkObstacle();
        // move forward
        moveForward();
    }
    delay(100);
}

// ultrasonic sensor distance
int readDistance() {
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);
  long duration = pulseIn(Echo_Pin, HIGH);
  int dist = duration * 0.034 / 2;
  return dist;
}

// detect left distance
int left_Distance() {
  myservo.write(0);  // servo turn left
  delay(500);
  int dist = readDistance();
  return dist;
}

// detect right distance
int right_Distance() {
  myservo.write(180);  // servo turn right
  delay(500);
  int dist = readDistance();
  return dist;
}

// stop moving
void moveStop() {
  motorLeft1.run(RELEASE);
  motorLeft2.run(RELEASE);
  motorRight1.run(RELEASE);
  motorRight2.run(RELEASE);
}

// move forward
void moveForward() {
  motorLeft1.run(FORWARD);
  motorLeft2.run(FORWARD);
  motorRight1.run(FORWARD);
  motorRight2.run(FORWARD);
}

// move backward
void moveBackward() {
  motorLeft1.run(BACKWARD);
  motorLeft2.run(BACKWARD);
  motorRight1.run(BACKWARD);
  motorRight2.run(BACKWARD);
}

// turn right
void turnRight() {
  motorLeft1.run(FORWARD);
  motorLeft2.run(FORWARD);
  motorRight1.run(BACKWARD);
  motorRight2.run(BACKWARD);
  delay(500);
  moveStop();
  turnedRight = true;
  turnedLeft = false;
}

// turn left
void turnLeft() {
  motorLeft1.run(BACKWARD);
  motorLeft2.run(BACKWARD);
  motorRight1.run(FORWARD);
  motorRight2.run(FORWARD);
  delay(500);
  moveStop();
  turnedLeft = true;
  turnedRight = false;
}

// reverse turn right
void reverseTurnRight() {
  motorLeft1.run(BACKWARD);
  motorLeft2.run(BACKWARD);
  motorRight1.run(FORWARD);
  motorRight2.run(FORWARD);
  delay(500);
  moveStop();
}

// reverse turn left
void reverseTurnLeft() {
  motorLeft1.run(FORWARD);
  motorLeft2.run(FORWARD);
  motorRight1.run(BACKWARD);
  motorRight2.run(BACKWARD);
  delay(500);
  moveStop();
}

// detect obstacle
void checkObstacle() 
{
    distance = readDistance();
    if (distance < 20) 
    {
        // detect obstacles, 
        moveStop();
        moveBackward();
        delay(1000);
        moveStop();
        // detect distance
        int leftDist = left_Distance();
        int rightDist = right_Distance();
        if (leftDist > rightDist) {
            turnLeft();
        } else {
            turnRight();
        }
        myservo.write(90);  // 舵机回到中间位置

        // 前进一段距离绕过障碍物
        moveForward();
        delay(1500); // 根据实际情况调整前进时间
        moveStop();

        // 转弯回到原来的直线位置
        if (turnedLeft) {
            turnRight();
            delay(1000);// 根据实际情况调整时间
            turnLeft();
            delay(1000);// 根据实际情况调整时间
        } else if (turnedRight) {
            turnLeft();
            delay(1000);// 根据实际情况调整时间
            turnRight();
            turnRight();// 根据实际情况调整时间
            delay(1000);
        }
    }
}

// 检测到边缘后转向
void turnAround() {
  moveStop();
  moveBackward();
  delay(1000);
  moveStop();

  // 检测左右距离
  int leftDist = left_Distance();
  int rightDist = right_Distance();

  if (leftDist > rightDist) {
    turnLeft();
  } else {
    turnRight();
  }

  myservo.write(90);  // 舵机回到中间位置
}
