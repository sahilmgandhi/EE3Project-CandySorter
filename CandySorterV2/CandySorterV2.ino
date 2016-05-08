#define RED_LED 9
#define GREEN_LED 10
#define BLUE_LED 11
#define LED_RECEIVER A4 

//int currentColor[] = {0, 0, 0};

//int threshConst = 10;

void setup() {
 pinMode(GREEN_LED, OUTPUT);
 pinMode(RED_LED, OUTPUT);
 pinMode(BLUE_LED, OUTPUT);
 pinMode(LED_RECEIVER, INPUT);
 Serial.begin(9600);

}

void loop() 
{
  int red = 0;
  int blue = 0;
  int green = 0;

  for (int i = 0; i < 10; i++)
  {
    analogWrite(RED_LED, 120);     
    red = analogRead(A4);
    Serial.println(red);
    delay(500);
    analogWrite(RED_LED, 0);
    delay(500);
    analogWrite(GREEN_LED, 120);
    green = analogRead(A4);
    Serial.println(green);
    delay(500);
    analogWrite(GREEN_LED, 0);
    delay(500);
    analogWrite(BLUE_LED, 120);
    blue = analogRead(A4);
    Serial.println(blue);
    delay(500);
    analogWrite(BLUE_LED, 0);
    Serial.println();
    delay(500);
  }
  
//  
//    int red, blue, green;
//    digitalWrite(RED_LED, HIGH);
//    red = analogRead(A4);
//    delay(100);
//    digitalWrite(RED_LED, LOW);
//    digitalWrite(GREEN_LED, HIGH);
//    green = analogRead(A4);
//    delay(100);
//    digitalWrite(GREEN_LED, LOW);
//    digitalWrite(BLUE_LED, HIGH);
//    blue = analogRead(A4);
//    delay(100);
//    digitalWrite(BLUE_LED, LOW);
//
//    Serial.print("The red is: ");
//    Serial.println(red);
//    Serial.print("The green is: ");
//    Serial.println(green);
//    Serial.print("The blue is: ");
//    Serial.println(blue);
}


