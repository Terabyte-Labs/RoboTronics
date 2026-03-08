/**

*/

const int gasSensor = A5; 
const int ledGreen = 2;
const int ledRed = 3;
char buffer[256];

void setup() {
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(gasSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int gasSensorValue = analogRead(gasSensor);
  sprintf(buffer,
          "The value sensed from gas sensor is: %d \n",
          gasSensorValue);
  Serial.print(buffer);
  delay(700);

}
