#include <analogWrite.h>”
const int redPin= 13;
const int greenPin= 12;
const int bluePin= 27;
const int button= 14;

int digitalPin= 33;

int analogPin= A0;

int sensorVal = 0;

int threshold = 1870;

int i = 0;

int mappedVal = 0;


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

//if button is pressed
  if(digitalRead(button) == LOW){
    Serial.println("button pressed");
    //change light color when button is pressed in range 0..2
    if (i < 2){
      i++;
    }else{
      i = 0;
    }
    delay(500);
  }

//if sound is detected
  if(digitalRead(digitalPin) == 1){
    Serial.println(sensorVal);
    //turn on light with correct color at level of sound volume
    analogWrite(myLights[i], mappedVal);
    delay(5);
    //turn light off light 
    analogWrite(myLights[i], 0);

    
    }
   else{
    //otherwise keep light off 
    analogWrite(myLights[i], 0);
    }

}
