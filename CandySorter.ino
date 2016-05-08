#define RED_LED 9
#define GREEN_LED 10
#define BLUE_LED 11
#define LED_RECEIVER A4                     // long side is negative

int thresholdRed [] = {0,0,0};
int thresholdGreen [] = {0,0,0};
int thresholdBlue [] = {0,0,0};

int currentColor [] = {0,0,0};

int baseRed = 0;
int baseGreen = 0;
int baseBlue = 0;

int threshConst = 30;

int delayV = 50;

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
//
//  for (int i = 0; i < threshConst; i++)
//  {
//    digitalWrite(RED_LED, HIGH);      // Callibrate the red
//    red = analogRead(A4);
//    Serial.print("Red threshold is: ");
//    Serial.println(red);
//    thresholdRed[0] += red;
//    delay(delayV);
//    digitalWrite(4, LOW);
//    delay(delayV);
//    digitalWrite(5, HIGH);
//    green = analogRead(A4);
//    thresholdRed[1] += green;
//    delay(delayV);
//    digitalWrite(5, LOW);
//    delay(delayV);
//    digitalWrite(6, HIGH);
//    blue = analogRead(A4);
//    thresholdRed[2] += blue;
//    delay(delayV);
//    digitalWrite(6, LOW);
//  }
//  thresholdRed[0]/= threshConst;
//  thresholdRed[1]/= threshConst;
//  thresholdRed[2]/= threshConst;
//  
//  //<------------->
//    // use the servo to turn the thing once 45 degrees
//  //<------------->
//  
//  for (int i = 0; i < threshConst; i++)
//  {
//    digitalWrite(RED_LED, HIGH);      // Callibrate the green
//    red = analogRead(A4);
//    thresholdGreen[0] += red;
//    delay(delayV);
//    digitalWrite(4, LOW);
//    delay(delayV);
//    digitalWrite(5, HIGH);
//    green = analogRead(A4);
//    thresholdGreen[1] += green;
//    delay(delayV);
//    digitalWrite(5, LOW);
//    delay(delayV);
//    digitalWrite(6, HIGH);
//    blue = analogRead(A4);
//    thresholdGreen[2] += blue;
//    delay(delayV);
//    digitalWrite(6, LOW);
//  }
//  thresholdGreen[0]/= threshConst;
//  thresholdGreen[1]/= threshConst;
//  thresholdGreen[2]/= threshConst;
//
//  //<------------->
//    // use the servo to turn the thing once 45 degrees
//  //<------------->
//  
//  for (int i = 0; i < threshConst; i++)
//  {
//    digitalWrite(RED_LED, HIGH);      // Callibrate the blue
//    red = analogRead(A4);
//    thresholdBlue[0] += red;
//    delay(delayV);
//    digitalWrite(4, LOW);
//    delay(delayV);
//    digitalWrite(5, HIGH);
//    green = analogRead(A4);
//    thresholdBlue[1] += green;
//    delay(delayV);
//    digitalWrite(5, LOW);
//    delay(delayV);
//    digitalWrite(6, HIGH);
//    blue = analogRead(A4);
//    thresholdBlue[2] += blue;
//    delay(delayV);
//    digitalWrite(6, LOW);
//  }
//  thresholdBlue[0]/= threshConst;
//  thresholdBlue[1]/= threshConst;
//  thresholdBlue[2]/= threshConst;
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
  currentColor[0] = 0;
  currentColor[1] = 0;
  currentColor[2] = 0;

  int red = 0;
  int blue = 0;
  int green = 0;

  for (int i = 0; i < threshConst; i++)
  {
    analogWrite(RED_LED, 120);     
    red = analogRead(A4);
    currentColor[0] += red;
    delay(500);
    analogWrite(RED_LED, 0);
    delay(500);
    analogWrite(GREEN_LED, 120);
    green = analogRead(A4);
    currentColor[1] += green;
    delay(500);
    analogWrite(GREEN_LED, 0);
    delay(500);
    analogWrite(BLUE_LED, 120);
    blue = analogRead(A4);
    currentColor[2] += blue;
    delay(500);
    analogWrite(BLUE_LED, 0);
  }
  currentColor[0]/= threshConst;
  currentColor[1]/= threshConst;
  currentColor[2]/= threshConst;

  Serial.print("The current red color is : ");
  Serial.println(currentColor[0]);
  Serial.print("The current green color is: ");
  Serial.println(currentColor[1]);
  Serial.print("The current blue color is: ");
  Serial.println(currentColor[2]);
  
  
  bool isRed = false;
  isRed = compareRed(currentColor[0]);
  bool isBlue = false;
  bool isGreen = false;
  delay(delayV);
  if (!isRed)
  {
      isBlue = compareBlue(currentColor[2]);
  }

  if (isRed == true)
    Serial.println("The object is red");
  else if (isBlue == true)
    Serial.println("The object is blue");
  else
    Serial.println("The object is green");

  delay(1000);
}

bool compareRed(int currRed)
{
    Serial.print("The current red color is : ");
    Serial.println(currRed);
    Serial.print("the threshold red color is : ");
    Serial.println(thresholdRed[0]);
    if ((currRed <= 687) && (currRed >= 682))
       return true;
//    if(currRed <= thresholdRed[0] + 5 && currRed >= thresholdRed[0] - 5)
//      return true;
    return false;    
}

bool compareBlue(int currBlue)
{
    Serial.print("The current blue color is : ");
    Serial.println(currBlue);
    Serial.print("the threshold blue color is : ");
    Serial.println(thresholdBlue[2]);
    if (currBlue <= 687 && currBlue >= 682)
        return true;
//    if (currBlue <= thresholdBlue[2] + 2 && currBlue >= thresholdBlue[2] - 2)
//      return true;
    return false;
}

