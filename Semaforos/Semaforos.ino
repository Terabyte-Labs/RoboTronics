// C++ code
//

const int GREEN_1 = 4;
const int RED_1 = 2;
const int YELLOW_1 = 3;

const int GREEN_2 = 7;
const int RED_2 = 5;
const int YELLOW_2 = 6;


const int DELAY = 1000;
const int BLINKS = 3;

void setup()
{
  // Semaforo 1
  pinMode(GREEN_1, OUTPUT);
  pinMode(RED_1, OUTPUT);
  pinMode(YELLOW_1, OUTPUT);
  
  // Semaforo 2
  pinMode(GREEN_2, OUTPUT);
  pinMode(RED_2, OUTPUT);
  pinMode(YELLOW_2, OUTPUT);
  
  digitalWrite(GREEN_1, LOW);
  digitalWrite(RED_1, LOW);
  digitalWrite(YELLOW_1, LOW);
  
  digitalWrite(GREEN_2, LOW);
  digitalWrite(RED_2, LOW);
  digitalWrite(YELLOW_2, LOW);
  
  
}

void loop()
{
  
  //
  digitalWrite(RED_1, HIGH);
  digitalWrite(GREEN_2, HIGH);
  delay(DELAY * 5);
  
  // blink Yellows
  digitalWrite(RED_1, LOW);
  digitalWrite(GREEN_2, LOW);
  blinkSemaphors();
  
  //change states
  digitalWrite(YELLOW_1, LOW);
  digitalWrite(YELLOW_2, LOW);
  digitalWrite(RED_2, HIGH);
  digitalWrite(GREEN_1, HIGH);
  delay(DELAY * 5);
  
  //
  digitalWrite(RED_2, LOW);
  digitalWrite(GREEN_1, LOW);
  blinkSemaphors();
  
}

void blinkSemaphors(){
  for(int i = 0 ; i < BLINKS ; i++){
  	digitalWrite(YELLOW_1, HIGH);
    digitalWrite(YELLOW_2, HIGH);
    delay(DELAY);
    digitalWrite(YELLOW_1, LOW);
    digitalWrite(YELLOW_2, LOW);
    delay(DELAY);
  }
}

