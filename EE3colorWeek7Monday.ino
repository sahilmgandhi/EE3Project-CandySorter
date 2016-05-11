#define RED_LED 9
#define GREEN_LED 10
#define BLUE_LED 11
#define LED_RECEIVER A4                     // long side is negative



int delayV = 30;
int flashConst = 15;
int delayFlash = 10;

int currentColor[] = {0, 0, 0};
int redRange[] = {30, 0, 0};
int blueRange[] ={0,0,0}; 

void setup(){
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(LED_RECEIVER, INPUT);
    Serial.begin(9600);
                      // so either the color has to meet the baseline, OR it is the least
}



void loop(){
  int red = 0;
  int blue = 0;
  int green = 0;
  int orange = 0;



  for (int i = 0; i < flashConst; i++)  //make sure to not count the first few because values need to stabilize
  {
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

    if(red > 15)
      isOrange = true;
    else
     isRed =true;
    
  else if (blue > red && blue > green)
    isBlue = true;

  

  if (isRed)
    Serial.println("The color is Red");
  else if(isYellow)
    Serial.println("The color is Yellow");
  else if (isBlue)
    Serial.println("The color is Blue");
  else if (isGreen)
    Serial.println("The color is Green");
   else if(isBrown)
    Serial.println("The color is Brown");
  else if(isOrange)
    Serial.println("The color is Orange");
  }
