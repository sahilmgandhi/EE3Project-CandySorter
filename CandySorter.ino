#define RED_LED 9
#define GREEN_LED 10
#define BLUE_LED 11
#define LED_RECEIVER A4                     // long side is negative

int thresholdRed [] = {0,0,0};
int thresholdGreen [] = {0,0,0};
int thresholdBlue [] = {0,0,0};

int threshConst = 30;
int flashConst = 5;
int delayFlash = 100;
int delayV = 50;

void setup(){
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(LED_RECEIVER, INPUT);
    Serial.begin(9600);
    getColorBaseline();                    // so either the color has to meet the baseline, OR it is the least
}

void getColorBaseline(){
    // get the baseline of each color (if that is even required ... maybe not if the M&M will be so close)
}

void loop(){
  int red = 0;
  int blue = 0;
  int green = 0;

  for (int i = 0; i < flashConst; i++)
  {
    analogWrite(RED_LED, 150);
    delay(3);     
    red = analogRead(A4);
    Serial.println(red);
    delay(delayFlash);
    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 150);
    delay(3);   
    green = analogRead(A4);
    Serial.println(green);
    delay(delayFlash);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 150);
    delay(3);   
    blue = analogRead(A4);
    Serial.println(blue);
    delay(delayFlash);
    analogWrite(BLUE_LED, 0);
    Serial.println();
    delay(delayFlash);
  }

  red /= flashConst;
  blue /= flashConst;
  green /= flashConst;

  bool isRed = false;
  bool isGreen = false;
  bool isBlue = false;

  if (red < green && red < blue)
    isRed = true;
  else if (blue < red && blue < green)
    isBlue = true;
  else
    isGreen = true;

  if (isRed)
    Serial.println("The color is Red");
  else if (isBlue)
    Serial.println("The color is Blue");
  else if (isGreen)
    Serial.println("The color is Green");
  
}

