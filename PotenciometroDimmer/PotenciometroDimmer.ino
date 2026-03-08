/**
  Tinker card link: https://www.tinkercad.com/things/9PnfIPTdvQW-leddimmer
  Author: Luis Enrique Gonzalez Hernandez
*/

// Define pin numbers
const int potPin = A5; 
const int ledPinUp = 9;  
const int ledPinDown = 6;
char buffer[256];

void setup() {
  Serial.begin(9600);
  pinMode(ledPinUp, OUTPUT);
  pinMode(ledPinDown, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(potPin);

  // usando map
  //int brightness   = map(sensorValue, 0, 1023, 0, 255);
  //int brightness2 = map(sensorValue, 0, 1023, 255, 0);
  
  // usando regla de 3 no muy exacta
  // We do a cast to lon to avoid overflow
  int brightness  = (long)sensorValue * 255/1023;
  int brightness2 = 255 - brightness;
  //usando shifts lo mas rapido
  //int value = sensorValue>>2;
  //int brightness  = value;
  //int brightness2 = 255 - value;

  sprintf(buffer, "The value sensed from potentiometer is: %d - brightness = %d, brightness2 = %d\n", sensorValue, brightness, brightness2);
  Serial.print(buffer);


  analogWrite(ledPinUp, brightness);
  analogWrite(ledPinDown, brightness2);
  delay(500);

}
