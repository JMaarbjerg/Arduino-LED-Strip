// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define REDPOT A1
#define GREENPOT A2
#define BLUEPOT A0
#define manuSwitch 7
#define autoSwitch 8
#define fadeSwitch 9
#define discoSwitch 10


#define FADESPEED 5     // make this higher to slow down

bool firstLoop = true;
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
bool manuState;
bool autoState;
bool fadeState;
bool discoState;

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(REDPOT, INPUT);
  pinMode(GREENPOT, INPUT);
  pinMode(BLUEPOT, INPUT);
  
  pinMode(manuSwitch, INPUT);
  pinMode(autoSwitch, INPUT);
  pinMode(fadeSwitch, INPUT);
  pinMode(discoSwitch, INPUT);
  
  //For debugging with the console
  Serial.begin(9600);
}

void loop(){
  manuState = digitalRead(manuSwitch);
  autoState = digitalRead(autoSwitch);
  fadeState = digitalRead(manuSwitch);
  discoState = digitalRead(fadeSwitch);
  Serial.println(manuState);
  //Serial.println(autoState);
  
  //Control for the MA part
  if(manuState == HIGH) {
    //manual();
    //Serial.println("manu");
  }
  else if (autoState == HIGH && fadeState == HIGH){
    //fade();
    Serial.println("AutoFade");
  }
  else if (autoState == HIGH && discoState == HIGH){
    //disco();
    //Serial.println("AutoDisco");
  }
}
     
void manual(){
    redValue = analogRead(REDPOT);
    float tempRed = redValue * (256.0 / 1023.0);
    analogWrite(REDPIN, tempRed);
    
    greenValue = analogRead(GREENPOT);
    float tempGreen = greenValue * (256.0 / 1023.0);
    analogWrite(GREENPIN, tempGreen);
    
    blueValue = analogRead(BLUEPOT);
    float tempBlue = blueValue * (256.0 / 1023.0);
    analogWrite(BLUEPIN, tempBlue);
    //Serial.println(tempBlue);
}

void disco(){
    //Set color to violet on first loop
    if(firstLoop){
    analogWrite(REDPIN, 256);
    analogWrite(BLUEPIN, 256);
    firstLoop = false;
    delay(FADESPEED);    
}
    
    //Set color to red
    analogWrite(BLUEPIN, 0);
    delay(FADESPEED);
    
    //Set color to yellow
    analogWrite(GREENPIN, 256);
    delay(FADESPEED);
    
    //Set color to green
    analogWrite(REDPIN, 0);
    delay(FADESPEED);
    
    //Set color to teal
    analogWrite(BLUEPIN, 256);
    delay(FADESPEED);
    
    //Set color to blue
    analogWrite(GREENPIN, 0);
    delay(FADESPEED);
    
    //Set color to violet
    analogWrite(REDPIN, 256);
    delay(FADESPEED);
  }
 
void fade() {
  int r, g, b;
 
  // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from red to yellow
  for (g = 0; g < 256; g++) { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  } 
  // fade from yellow to green
  for (r = 255; r > 0; r--) { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from green to teal
  for (b = 0; b < 256; b++) { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  } 
}
