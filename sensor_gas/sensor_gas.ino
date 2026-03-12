/**
  Detector de Gas Mario Bros Edition
*/

const int gasSensor = A5; 
const int ledYellow = 3;
const int ledRed = 2;
const int ledGreen = 4;
const int pinBuzzer = 5;

// Notas en octava alta (E7, C7, G7) para que el pasivo suene nítido
int melody[] = {
  2637, 2637, 0, 2637, 0, 2093, 2637, 0, 3136, 1568, // Intro icónico
  2093, 1568, 1319, 1760, 1976, 1865, 1760, 1568, 2637, 3136, 3520, 2794, 3136, 2637, 2093
};

int duration[] = {
  80, 80, 40, 80, 40, 80, 80, 40, 80, 150,
  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
};

void setup() {
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
  Serial.println("Semaforo de Gas Mario: Iniciado");
}

void loop() {
  
  int gasSensorValue = averageRead(gasSensor, 20);

  // 2. Lógica de estados (Semáforo)
  if(gasSensorValue <= 105) { 
    Serial.print("Estado Seguro: ");
    Serial.println(gasSensorValue);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
    noTone(pinBuzzer);
  } 
  else if(gasSensorValue < 180) {
    Serial.print("Advertencia: ");
    Serial.println(gasSensorValue);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
    
    // Un pequeño "chirp" de aviso cada vez que detecta algo en amarillo
    tone(pinBuzzer, 1500, 50); 
    delay(100);
    noTone(pinBuzzer);
  } 
  else {
    Serial.print("!!! FUGA DETECTADA !!!: ");
    Serial.println(gasSensorValue);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
    // 3. Activar alarma musical
    marioWarning(); 
  }

  delay(100); 
}

int averageRead(int pin, int samples) {
  long sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(5);
  }
  return sum / samples;
}

void marioWarning() {
  for(int j = 0 ; j < 2; j++){
    for (int i = 0; i < 25; i++) {
      if (melody[i] == 0) {
        delay(duration[i]);
      } else {
        // Usamos tone() porque confirmamos que es pasivo
        tone(pinBuzzer, melody[i], duration[i]);
      
        // El LED rojo parpadea con cada nota
        digitalWrite(ledRed, HIGH);
        delay(duration[i] * 1.2); // El 1.2 da el espacio musical entre notas
        digitalWrite(ledRed, LOW);
      }
    }
  } 
  noTone(pinBuzzer);
}