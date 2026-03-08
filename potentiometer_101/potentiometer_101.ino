// Define pin numbers
const int potPin = A5;  // Potentiometer connected to analog pin A0
const int ledPin = 9;   // LED connected to digital pin 9 (must support PWM)
char buffer[256]; // 

void setup() {
  // PinMode not strictly necessary for analogRead, but good practice
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // Read the raw value from the potentiometer (0 to 1023)
  int sensorValue = analogRead(potPin);
  // Map the sensor value to an LED brightness range (0 to 255)
  int brightness = map(sensorValue, 0, 1023, 0, 255);
  sprintf(buffer, "The value sensed from potentiometer is: %d which correlates to a brightness of %d\n", sensorValue, brightness);
  Serial.println(buffer);

  // Use the mapped value to set the LED brightness
  analogWrite(ledPin, brightness);
  delay(500);
}
