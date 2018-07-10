#include <math.h>

double celsius;
double fahrenheit;
const int ntc = A1;
//const int button = A0;
int interruptPin = 2;
int count = 0;
int dp = A4;
int buttonState = LOW;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;
int red = A7 ;
int blue = A6;
int green = A3;
int ledState = -1;
int a ;
int last = 0;
int num_array[10][7] = {  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 0, 0, 1, 1 } //9
};
void setup() {
  // put your setup code here, to run once:
  pinMode(ntc, INPUT);
  //pinMode(button,INPUT);
  pinMode(2, INPUT); // 2 PE BUTTON HAI.
  for (int i = 3; i <= 13; i++)
    pinMode(i, OUTPUT);
 
  pinMode(dp, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  a = analogRead(ntc);
  Thermistor(a);
  celsius = (int) celsius;
  fahrenheit = (int)fahrenheit;
  buttonState = digitalRead(2);
  if (buttonState == 0)
    buttonState = 1;
  else
    buttonState = 0;
  if ( (millis() - lastDebounceTime) > debounceDelay) {

    //if the button has been pressed, lets toggle the LED from "off to on" or "on to off"
    if ( (buttonState == HIGH) && (ledState < 0) ) {
      mode();

     
      ledState = -ledState; //now the LED is on, we need to change the state
      lastDebounceTime = millis(); //set the current time
    }
    else if ( (buttonState == HIGH) && (ledState > 0) ) {
      ssd(last);
      //digitalWrite(ledPin, LOW); //turn LED off
      ledState = -ledState; //now the LED is off, we need to change the state
      lastDebounceTime = millis(); //set the current time
    }//close if/else

  }//close if(time buffer)

  /*
   * THIS FUNCTION DISPLAYS THE DIFF THINGS ON SSD(SEVEN SEGMENT DIGIT)
   */
  if (count % 3 == 0)
    ssd(a);
  else if (count % 3 == 1)
    ssd(celsius);
  else   
     ssd(fahrenheit);
  /*
   * THIS LIGHTS THE LED BASED UPON THE TEMPERATURE RANGE
   */
 /* if(celsius <15){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
  }
  else if(celsius >=15 && celsius <=30){
  digitalWrite(blue,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(red,LOW);
  }
  else{
  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  }
*/if(celsius <=10){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
   }
  else if( celsius <=15)
  {
    digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
   digitalWrite(green,LOW);
  }
  else
  {
    digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
  }         
       
  /*
   * THIS IS JUST TO FIND , KI KYA CHAL RAHA HAI CODE MAI, PRINTING THE VALUE ON SERIAL.
   */
 // Serial.println(a);
  Serial.println(celsius);
  //Serial.println(" new info");

}
/*
 * THE MODE FUNCTION, LIGHTS UP THE DP
 */
void mode() {
  if (count % 3 == 0) {

    digitalWrite(10, HIGH);

    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    for (int i = 3; i <= 9; i++)
      digitalWrite(i, LOW);
    digitalWrite(dp, HIGH);
    delay(500);
    for (int i = 10; i <= 13; i++)
      digitalWrite(i, LOW);
    digitalWrite(dp, LOW);

    Serial.println(count);
    Serial.println("1 ");
   

  } else if (count % 3 == 1) {

    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    for (int i = 3; i <= 9; i++)
      digitalWrite(i, LOW);
    digitalWrite(dp, HIGH);
    Serial.println(count);
    Serial.println("2 ");
    delay(500);
    for (int i = 10; i <= 13; i++)
      digitalWrite(i, LOW);
    digitalWrite(dp, LOW);
   
  }
  else {

    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);

    for (int i = 3; i <= 9; i++)
      digitalWrite(i, LOW);
    digitalWrite(dp, HIGH);
    delay(500);
    Serial.println(count);
    Serial.println("3 ");
    for (int i = 10; i <= 13; i++)
      digitalWrite(i, LOW);
    digitalWrite(dp, LOW);
   
  }
  count ++;
}
/*
 * THIS ACTUALLY CONVERTS THE ANALOG VALUE OF NTC INTO CELSIUS AND FAHREINHEIT
 */
void Thermistor(int RawADC) {
  double Temp;
  // Temp = log(10000.0*((1024.0/RawADC-1)));
  Temp        = log(10000.0 / (1024.0 / RawADC - 1)) ; // for pull-up configuration
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  celsius = Temp - 273.15;            // Convert Kelvin to Celcius
  fahrenheit = (celsius * 9.0) / 5.0 + 32.0; // Convert Celcius to Fahrenheit

}
/*
 * THIS ACTALLY DISPLAYS THE DIGIT ON THE SSD. IT DIFFERENTIATED DIFF INDIVIDUAL DIGIT IN A LOOP
 */
void ssd(int temp) {
  int t = temp;
  last = temp;
  int i = 0;
  String str = String(t);
  char vc[str.length()];
  str.toCharArray(vc, str.length());

  while (t > 0) {
    int rem = t % 10;
    t = t / 10;
    for (int k = 0; k < 4; k++) {
      if (k == i)
        digitalWrite(10 + k, HIGH);
      else
        digitalWrite(10 + k, LOW);
    }

    Num_Write(rem);
    i++;
    delay(5);
  }
}
/*
 * THIS PRINTS OUT THE INDIVIDUAL DIGIT.
 */
void Num_Write(int number)
{
  int pin = 3;

  for (int j = 0; j < 7; j++) {

    digitalWrite(pin, num_array[number][j]);
    pin++;

  }

}


