#define RED_LED 4
#define GREEN_LED 5
#define BLUE_LED 6
#define LED_RECEIVER A4                     // long side is negative

int thresholdRed [] = {0,0,0};
int thresholdGreen [] = {0,0,0};
int thresholdBlue [] = {0,0,0};

int currentColor [] = {0,0,0};

int baseRed = 0;
int baseGreen = 0;
int baseBlue = 0;

int threshConst = 30;

int delayV = 100;

void setup() {
  // put your setup code here, to run once:
 pinMode(GREEN_LED, OUTPUT);
 pinMode(RED_LED, OUTPUT);
 pinMode(BLUE_LED, OUTPUT);
 pinMode(LED_RECEIVER, INPUT);
 Serial.begin(9600);

 goToThreshold();
}

void goToThreshold()
{
  int red, blue, green;

  for (int i = 0; i < threshConst; i++)
  {
    digitalWrite(RED_LED, HIGH);      // Callibrate the red
    red = analogRead(A4);
    thresholdRed[0] += red;
    delay(delayV);
    digitalWrite(4, LOW);
    delay(delayV);
    digitalWrite(5, HIGH);
    green = analogRead(A4);
    thresholdRed[1] += green;
    delay(delayV);
    digitalWrite(5, LOW);
    delay(delayV);
    digitalWrite(6, HIGH);
    blue = analogRead(A4);
    thresholdRed[2] += blue;
    delay(delayV);
    digitalWrite(6, LOW);
  }
  thresholdRed[0]/= threshConst;
  thresholdRed[1]/= threshConst;
  thresholdRed[2]/= threshConst;
  //<------------->
    // use the servo to turn the thing once 45 degrees
  //<------------->
  
  for (int i = 0; i < threshConst; i++)
  {
    digitalWrite(RED_LED, HIGH);      // Callibrate the green
    red = analogRead(A4);
    thresholdGreen[0] += red;
    delay(delayV);
    digitalWrite(4, LOW);
    delay(delayV);
    digitalWrite(5, HIGH);
    green = analogRead(A4);
    thresholdGreen[1] += green;
    delay(delayV);
    digitalWrite(5, LOW);
    delay(delayV);
    digitalWrite(6, HIGH);
    blue = analogRead(A4);
    thresholdGreen[2] += blue;
    delay(delayV);
    digitalWrite(6, LOW);
  }
  thresholdGreen[0]/= threshConst;
  thresholdGreen[1]/= threshConst;
  thresholdGreen[2]/= threshConst;

  //<------------->
    // use the servo to turn the thing once 45 degrees
  //<------------->
  
  for (int i = 0; i < threshConst; i++)
  {
    digitalWrite(RED_LED, HIGH);      // Callibrate the blue
    red = analogRead(A4);
    thresholdBlue[0] += red;
    delay(delayV);
    digitalWrite(4, LOW);
    delay(delayV);
    digitalWrite(5, HIGH);
    green = analogRead(A4);
    thresholdBlue[1] += green;
    delay(delayV);
    digitalWrite(5, LOW);
    delay(delayV);
    digitalWrite(6, HIGH);
    blue = analogRead(A4);
    thresholdBlue[2] += blue;
    delay(delayV);
    digitalWrite(6, LOW);
  }
  thresholdBlue[0]/= threshConst;
  thresholdBlue[1]/= threshConst;
  thresholdBlue[2]/= threshConst;
}

void loop() {
  // put your main code here, to run repeatedly:

  // now here we have to compare everything to the thresholds. 

  // Pseudocode:
  /*
   * Collect the red, green, and blue. Store it into currentColor
   * Compare the red with the redThreshold, blueThreshold, Greenthreshold reds 
   *      - if it is equal to the redThreshold, then it is a red color
   * Compare the blue with the 3 thresholds
   *      - if it is equal to the blueThreshold (or around it, we can do plus of minus 5), then it is a blue color
   *      
   * Compare the red and the blue with the green. If it is similar to both of those, then it is a green colored      
   */
  
  digitalWrite(RED_LED, HIGH);
  int red, blue, green;
  for (int i = 0; i < threshConst; i++)
  {
    red = analogRead(A4);
    currentColor[0] += red; 
    delay(5);
  }
  digitalWrite(RED_LED, LOW);
  currentColor[0] /= threshConst;

  bool isRed = compareRed(currentColor[0]);
  bool isBlue = false;
  bool isGreen = false;
  delay(delayV);
  if (!isRed)
  {
      digitalWrite(BLUE_LED, HIGH);
      for (int i = 0; i < threshConst; i++)
      {
        blue = analogRead(A4);
        currentColor[1] += blue; 
        delay(5);
      }
      currentColor[1] /= threshConst;
      isBlue = compareBlue(currentColor[1]);
  }

  digitalWrite(BLUE_LED, LOW);
  if (isRed)
    Serial.println("The object is red");
  else if (isBlue)
    Serial.println("The object is blue");
  else
    Serial.println("The object is green");
    
//  
//  int baseRed = analogRead(LED_RECEIVER);
//
//  Serial.print("Red light is ");
//  Serial.println(baseRed);
//  delay(250);
//  digitalWrite(RED_LED, LOW);
//  delay(250);
//  digitalWrite(GREEN_LED, HIGH);
//  baseGreen = analogRead(LED_RECEIVER);
//  Serial.print("Green light is ");
//  Serial.println(baseGreen);
//  delay(250);
//  digitalWrite(GREEN_LED, LOW);
//  delay(250);
//  digitalWrite(BLUE_LED, HIGH);
//  baseBlue = analogRead(LED_RECEIVER);
//  Serial.print("Blue light is ");
//  Serial.println(baseBlue);
//  delay(250);
//  digitalWrite(BLUE_LED, LOW);
//  delay(250);
}

bool compareRed(int currRed)
{
    Serial.print("The current red color is : ");
    Serial.println(currRed);
    Serial.print("the threshold red color is : ");
    Serial.println(thresholdRed[0]);
    if(currRed <= thresholdRed[0] + 5 && currRed >= thresholdRed[0] - 5)
      return true;
    return false;    
}

bool compareBlue(int currBlue)
{
    Serial.print("The current blue color is : ");
    Serial.println(currBlue);
    Serial.print("the threshold blue color is : ");
    Serial.println(thresholdBlue[2]);
    if (currBlue <= thresholdBlue[2] + 5 && currBlue >= thresholdBlue[2] - 5)
      return true;
    return false;
}

