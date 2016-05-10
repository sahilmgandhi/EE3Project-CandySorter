//#define RED_LED 9
//#define GREEN_LED 10
//#define BLUE_LED 11
//#define LED_RECEIVER A4                     // long side is negative
//#include <Servo.h>
//
//Servo myServo;
//
//int redCupPos = 0;
//int blueCupPos = 90;
//int greenCupPos = 180;
//
//int flashConst = 10;
//int delayFlash = 200;
//int delayV = 100;
//
//void setup(){
//    pinMode(GREEN_LED, OUTPUT);
//    pinMode(RED_LED, OUTPUT);
//    pinMode(BLUE_LED, OUTPUT);
//    pinMode(LED_RECEIVER, INPUT);
//
//    myServo.attach(A0);
//    myServo.write(0);
//    Serial.begin(9600);
//}
//
//void loop(){
//  int red = 0;
//  int blue = 0;
//  int green = 0;
//
//  for (int i = 0; i < flashConst; i++)
//  {
//    analogWrite(RED_LED, 150);
//    delay(delayV);     
//    red = analogRead(A4);
//    Serial.println(red);
//    delay(delayFlash);
//    analogWrite(RED_LED, 0);
//    analogWrite(GREEN_LED, 150);
//    delay(delayV);   
//    green = analogRead(A4);
//    Serial.println(green);
//    delay(delayFlash);
//    analogWrite(GREEN_LED, 0);
//    analogWrite(BLUE_LED, 150);
//    delay(delayV);   
//    blue = analogRead(A4);
//    Serial.println(blue);
//    delay(delayFlash);
//    analogWrite(BLUE_LED, 0);
//    Serial.println();
//    delay(delayFlash);
//  }
//
//  red /= flashConst;
//  blue /= flashConst;
//  green /= flashConst;
//
//  bool isRed = false;
//  bool isGreen = false;
//  bool isBlue = false;
//
//  if (red > green && red > blue)
//    isRed = true;
//  else if (blue > red && blue > green)
//    isBlue = true;
//  else
//    isGreen = true;
//
//  if (isRed)
//    Serial.println("The color is Red");
//  else if (isBlue)
//    Serial.println("The color is Blue");
//  else if (isGreen)
//    Serial.println("The color is Green");
//  
//}

// in setup: myServo.attach(#Pinnumber); myServo.write(90); // sets the servo to the midpoint

// in loop: myServo.write(redCupPos);


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 40;    // variable to store the servo position

void setup() {
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo.write(40);
  Serial.begin(9600);
}

void loop() {
  for (pos = 40; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(100);                       // waits 15ms for the servo to reach the position
  }

  myservo.write(40);

  delay(500);
}

