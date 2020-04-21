#include <analogWrite.h>”
const int redPin= 13;
const int greenPin= 12;
const int bluePin= 27;
const int button= 14;
int digitalPin= 33;
int analogPin= A0;
int sensorVal = 0;
int threshold = 1870;
int randNumber = random(0,3);
int mappedVal = 0;
boolean turn_on = false; 
int myLights[]= {redPin, greenPin, bluePin};

void setup() {
  // put your setup code here, to run once:

  pinMode(digitalPin, INPUT);
  pinMode(analogPin,INPUT);
  pinMode(button, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}



void loop() {
//get analog value
sensorVal = analogRead(analogPin);

//map to 255 LED brightness range 
mappedVal = map(sensorVal, 1800, 1860, 0, 255);

//if button pressed, turn on
if(digitalRead(button) == LOW && turn_on == false){
  delay(500);
  turn_on = true;
  
  
  } 
  
//if button pressed, turn off
if(digitalRead(button) == LOW && turn_on == true){
  delay(500);
  turn_on = false;
  } 

//if on, activate sound
if(turn_on == true){
  //if sound is detected
  if(digitalRead(digitalPin) == 1){
    analogWrite(myLights[0], 0);
    Serial.println(sensorVal);
    //turn on light with correct color at level of sound volume
    randNumber = random(0,3);
    analogWrite(myLights[randNumber], mappedVal);
    delay(5);
    //turn light off light 
    analogWrite(myLights[randNumber], 0);

    
    }
   else{
    //otherwise turn red to indicate no sound
    analogWrite(myLights[0], 255);
    }
  
  }else{
    //no lights because it's off
    analogWrite(myLights[0], 0);

}


}
