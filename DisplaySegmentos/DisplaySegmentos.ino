// C++ code
//
const int SEGMENTO_A = 2;
const int SEGMENTO_B = 3;
const int SEGMENTO_C = 4;
const int SEGMENTO_D = 5;
const int SEGMENTO_E = 6;
const int SEGMENTO_F = 7;
const int SEGMENTO_G = 8;
const int DELAY = 300;

void setup()
{

  pinMode(SEGMENTO_A, OUTPUT); // a
  pinMode(SEGMENTO_B, OUTPUT); // b
  pinMode(SEGMENTO_C, OUTPUT); // c
  pinMode(SEGMENTO_D, OUTPUT); // d
  pinMode(SEGMENTO_E, OUTPUT); // e
  pinMode(SEGMENTO_F, OUTPUT); // f
  pinMode(SEGMENTO_G, OUTPUT); // g
  initSegments();
  
}

void loop()
{
  //0
  initSegments();
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_B);
  activateSegment(SEGMENTO_C);
  activateSegment(SEGMENTO_D);
  activateSegment(SEGMENTO_E);
  activateSegment(SEGMENTO_F);
  delay(DELAY);
  
  // 1
  deActivateSegment(SEGMENTO_A);
  deActivateSegment(SEGMENTO_D);
  deActivateSegment(SEGMENTO_E);
  deActivateSegment(SEGMENTO_F);
  delay(DELAY);
  
  // 2
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_G);
  activateSegment(SEGMENTO_E);
  activateSegment(SEGMENTO_D);
  deActivateSegment(SEGMENTO_C);
  delay(DELAY);
  
  // 3
  activateSegment(SEGMENTO_C);
  activateSegment(SEGMENTO_G);
  deActivateSegment(SEGMENTO_E);
  delay(DELAY);
  
  // 4
  activateSegment(SEGMENTO_F);
  deActivateSegment(SEGMENTO_A);
  deActivateSegment(SEGMENTO_D);
  delay(DELAY);
  
  // 5
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_D);
  deActivateSegment(SEGMENTO_B);
  delay(DELAY);
  
  // 6
  activateSegment(SEGMENTO_E);
  delay(DELAY);
  
  // 7
  activateSegment(SEGMENTO_B);
  deActivateSegment(SEGMENTO_D);
  deActivateSegment(SEGMENTO_E);
  deActivateSegment(SEGMENTO_F);
  deActivateSegment(SEGMENTO_G);
  delay(DELAY);
  
  // 8
  activateSegment(SEGMENTO_D);
  activateSegment(SEGMENTO_E);
  activateSegment(SEGMENTO_F);
  activateSegment(SEGMENTO_G);
  delay(DELAY);
  
  // 9
  deActivateSegment(SEGMENTO_E);
  delay(DELAY);
}

void initSegments(){
  deActivateSegment(SEGMENTO_A);
  deActivateSegment(SEGMENTO_B);
  deActivateSegment(SEGMENTO_C);
  deActivateSegment(SEGMENTO_D);
  deActivateSegment(SEGMENTO_E);
  deActivateSegment(SEGMENTO_F);
  deActivateSegment(SEGMENTO_G);
}

void activateSegment(int segment){
	digitalWrite(segment, HIGH);
}

void deActivateSegment(int segment){
	digitalWrite(segment, LOW);
}