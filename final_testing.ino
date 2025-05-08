#include <AFMotor.h>     // libraray for motor shield
#include <Servo.h>       // libraray for servo motor
#include <NewPing.h>     // libraray for ultrasonic sensor

const int Trig_Pin =A4;
const int Echo_Pin =A5;
const int Max_Speed =150;
const int Max_Dist = 250;

NewPing ultra_sonic(Trig_Pin, Echo_Pin, Max_Dist);

AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
AF_DCMotor motor3(3,MOTOR34_1KHZ);
AF_DCMotor motor4(4,MOTOR34_1KHZ);

int Ls = A0;
int Rs = A1;

Servo myservo;

int distance=250;
int speedSet=0;
boolean goesForward=false;

void setup() {
  
  myservo.attach(10);
  myservo.write(0);
  delay(2000);
  distance=readDistance();
  delay(100);
  moveForward();
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop() 
{
 int edgeLeft = digitalRead(Ls);
 int edgeRight = digitalRead(Rs);

 if(edgeLeft == LOW  && edgeRight == LOW)
 {
  int dist_R = 0;
  int dist_L = 0;
  delay(100);
  if(distance<=25){
   moveStop();
   delay(100);
   moveBackward();
   delay(200);
   moveStop();
   delay(100);
   dist_R = right_Distance();
   delay(100);
   dist_L = left_Distance();
   delay(100);

   if(dist_R <= dist_L){
    turnRight();
    moveStop();
   }else{
    turnLeft();
    moveStop();
   }
  }
  else{
   moveForward();
  }
  distance = readDistance();
 }

 else if(edgeLeft == HIGH  || edgeRight == HIGH)
 {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(700);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(700);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
 }
}


int left_Distance(){
  myservo.write(170);
  delay(500);
  int dist = readDistance();
  delay(100);
  myservo.write(90);
  return dist;
  delay(100); 
}

int right_Distance(){
   myservo.write(10);
  delay(500);
  int dist = readDistance();
  delay(100);
  myservo.write(90);
  return dist;
  delay(100);
}

int readDistance(){
  int cm = ultra_sonic.ping_cm();
  if(cm<=0){                        // this is done in case when sensor gives -ve value which is absurd
   cm=250;
     }
 return cm;
}

void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  } 

void moveForward() {

 if(!goesForward)
  {
  goesForward=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
   for (speedSet = 0; speedSet < Max_Speed; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
   {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
   }
  }
}
void moveBackward() {
  goesForward=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < Max_Speed; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD); 
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD); 
}
