#define RED_LED 4
#define GREEN_LED 5
#define BLUE_LED 6
#define LED_RECEIVER A4                     // long side is negative

int thresholdRed [] = {0,0,0};
int thresholdGreen [] = {0,0,0};
int threshholdBlue [] = {0,0,0};

int currentColor [] = {0,0,0};

int baseRed = 0;
int baseGreen = 0;
int baseBlue = 0;

int threshConst = 10;

void setup() {
  // put your setup code here, to run once:
 pinMode(GREEN_LED, OUTPUT);
 pinMode(RED_LED, OUTPUT);
 pinMode(BLUE_LED, OUTPUT);
 pinMode(LED_RECEIVER, INPUT);
 Serial.begin(9600);

 gotoThreshold();
}

void goToThreshold()
{
  int red, blue, green;

  for (int i = 0; i < threshConst; i++)
  {
    digitalWrite(RED_LED, HIGH);      // Callibrate the red
    red = analogRead(A4);
    threshholdRed[0] += red;
    delay(20);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    green = analogRead(A4);
    thresholdRed[1] += green;
    delay(20);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    blue = analogRead(A4);
    thresholdRed[2] += blue;
    delay(20);
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
    threshholdGreen[0] += red;
    delay(20);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    green = analogRead(A4);
    thresholdGreen[1] += green;
    delay(20);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    blue = analogRead(A4);
    thresholdGreen[2] += blue;
    delay(20);
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
    threshholdBlue[0] += red;
    delay(20);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    green = analogRead(A4);
    thresholdBlue[1] += green;
    delay(20);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    blue = analogRead(A4);
    thresholdBlue[2] += blue;
    delay(20);
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

    
  int baseRed = analogRead(LED_RECEIVER);

  Serial.print("Red light is ");
  Serial.println(baseRed);
  delay(250);
  digitalWrite(RED_LED, LOW);
  delay(250);
  digitalWrite(GREEN_LED, HIGH);
  baseGreen = analogRead(LED_RECEIVER);
  Serial.print("Green light is ");
  Serial.println(baseGreen);
  delay(250);
  digitalWrite(GREEN_LED, LOW);
  delay(250);
  digitalWrite(BLUE_LED, HIGH);
  baseBlue = analogRead(LED_RECEIVER);
  Serial.print("Blue light is ");
  Serial.println(baseBlue);
  delay(250);
  digitalWrite(BLUE_LED, LOW);
  delay(250);
}

