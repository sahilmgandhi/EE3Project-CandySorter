#define RED_LED 3
#define GREEN_LED 5
#define BLUE_LED 6
#define LED_RECEIVER A4                     // long side is negative

#include <Servo.h>
Servo ramp;

Servo piston;

int delayV = 20;
int flashConst = 30;
int delayFlash = 10;

void setup(){
    ramp.attach(9);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(LED_RECEIVER, INPUT);
    Serial.begin(9600);

    piston.attach(10);  //?? will this work ... technically shouldn't work since no pwm on pin 10 ... but same as above with pin 9
    piston.write(0);
}



void loop(){
  int red = 0;
  int blue = 0;
  int green = 0;
  int orange = 0;



  for (int i = 0; i < flashConst; i++)  //make sure to not count the first few because values need to stabilize
  {
    if (i < 4)
    {
      analogWrite(RED_LED, 200);
    delay(delayV);     
    
    delay(delayFlash);
    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 200);
    delay(delayV);       
   
    delay(delayFlash);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 200);
    delay(delayV);       
    
    delay(delayFlash);
    analogWrite(BLUE_LED, 0);
   
    delay(delayFlash);
    continue;
    }
    analogWrite(RED_LED, 200);
    delay(delayV);     
    red += analogRead(A4);
    
    delay(delayFlash);
    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 200);
    delay(delayV);   
    green += analogRead(A4);
   
    delay(delayFlash);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 200);
    delay(delayV);   
    blue += analogRead(A4);
    
    delay(delayFlash);
    analogWrite(BLUE_LED, 0);
   
    delay(delayFlash);

    
    
  }

  red /= flashConst;
  green /= flashConst;
  blue /= flashConst;
  orange /= flashConst;

Serial.println();
  Serial.print(red);
  Serial.print(" ");
  Serial.print(green);
  Serial.print(" ");
  Serial.print(blue);

  Serial.println();
  
  Serial.println();

  



  bool isRed = false;
  bool isGreen = false;
  bool isBlue = false;
  bool isBrown = false;
  bool isOrange = false;
  bool isYellow = false;

  int errorRG = red - green;
  if(errorRG < 0)
    errorRG *= -1;

  if(blue < 10 && red < 10 && green < 10)
    isBrown = true;

  else if(blue > 20)
    isBlue = true;

  else if(green > red && green > blue)
    isGreen = true;
  
  else if (errorRG < 15 && green > 10)
    isYellow = true;

  else if (red > green && red > blue)

    if(red > 17)                        // change this value based on what it tells in class ... we just need to re-callibrate this every time ... =(
      isOrange = true;
    else
     isRed =true;
    
  else if (blue > red && blue > green)
    isBlue = true;

  

 if (isRed)
  {
    Serial.println("The color is Red");
    ramp.write(0);
  }
  else if(isYellow)
  {
    Serial.println("The color is Yellow");
    ramp.write(45);
  }
  else if (isBlue)
  {
    Serial.println("The color is Brown");
    ramp.write(90);
  }
  else if (isGreen)
  {
    Serial.println("The color is Green");
    ramp.write(135);
  }
  else if(isBrown)
  {
    Serial.println("The color is Brown");
    ramp.write(90);
  }
  else if(isOrange)
  {
    Serial.println("The color is Orange");
    ramp.write(180);
  }

  piston.write(160);         // code to make the piston push the candy forward and then retract
  delay(1000);
  piston.write(1);
  delay(1000);
  piston.write(160);
  
 
}
