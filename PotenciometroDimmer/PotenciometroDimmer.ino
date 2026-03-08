/**
  Tinker card link: https://www.tinkercad.com/things/9PnfIPTdvQW-leddimmer
  Author: Luis Enrique Gonzalez Hernandez
*/

#include <math.h>

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

  // Normalizar el valor del ADC (0–1023 → 0.0–1.0)
  float normalized = sensorValue / 1023.0;

  // Gamma típica para percepción humana
  float gamma = 2.2;

  // Aplicar corrección gamma
  int brightness  = (int)(pow(normalized, gamma) * 255.0);
  int brightness2 = 255 - brightness;

  sprintf(buffer,
          "The value sensed from potentiometer is: %d - brightness = %d, brightness2 = %d\n",
          sensorValue, brightness, brightness2);

  Serial.print(buffer);

  analogWrite(ledPinUp, brightness);
  analogWrite(ledPinDown, brightness2);

  delay(500);
}