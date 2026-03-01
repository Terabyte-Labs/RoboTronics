/**
  Programa que controla un display de 7 segmentos catado comun (-)

  Se definieron los segmentos como constantes para un facil manejo y referencia de los segmentos
  Se creraron metodos de utilidad para activar y desactivar el segmento
  Se creo otro metodo el cual desactiva todos los segmentos
  
*/
const int SEGMENTO_A = 2;
const int SEGMENTO_B = 3;
const int SEGMENTO_C = 4;
const int SEGMENTO_D = 5;
const int SEGMENTO_E = 6;
const int SEGMENTO_F = 7;
const int SEGMENTO_G = 8;
const int DELAY = 1250;

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
  // 1
  initSegments();
  activateSegment(SEGMENTO_B);
  activateSegment(SEGMENTO_C);
  delay(DELAY);
  
  // 2
  initSegments();
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_B);
  activateSegment(SEGMENTO_D);
  activateSegment(SEGMENTO_E);
  activateSegment(SEGMENTO_G);
  
  delay(DELAY);
  
  // 3
  initSegments();
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_B);
  activateSegment(SEGMENTO_C);
  activateSegment(SEGMENTO_D);
  activateSegment(SEGMENTO_G);
  
  delay(DELAY);
  
  // 4
  initSegments();
  activateSegment(SEGMENTO_B);
  activateSegment(SEGMENTO_C);
  activateSegment(SEGMENTO_F);
  activateSegment(SEGMENTO_G);
  
  delay(DELAY);
  
  // 5
  initSegments();
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_C);
  activateSegment(SEGMENTO_D);
  activateSegment(SEGMENTO_F);
  activateSegment(SEGMENTO_G);
  
  delay(DELAY);
  
  // 6
  initSegments();
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_C);
  activateSegment(SEGMENTO_D);
  activateSegment(SEGMENTO_E);
  activateSegment(SEGMENTO_F);
  activateSegment(SEGMENTO_G);
  
  delay(DELAY);
  
  // 7
  initSegments();
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_B);
  activateSegment(SEGMENTO_C);
  delay(DELAY);
  
  // 8
  initSegments();
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_B);
  activateSegment(SEGMENTO_C);
  activateSegment(SEGMENTO_D);
  activateSegment(SEGMENTO_E);
  activateSegment(SEGMENTO_F);
  activateSegment(SEGMENTO_G);
  
  delay(DELAY);
  
  // 9
  initSegments();
  activateSegment(SEGMENTO_A);
  activateSegment(SEGMENTO_B);
  activateSegment(SEGMENTO_C);
  activateSegment(SEGMENTO_D);
  activateSegment(SEGMENTO_F);
  activateSegment(SEGMENTO_G);
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