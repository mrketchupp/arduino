#include <she

// Definir pines de conexión
int pirPin = 2;
int ledPin = 13;

// Crea variables
int val = 0;
bool motionState = false; // Empezamos sin detectar movimiento.

void setup() {
  // Configure los pines como entrada o salida
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  // Comience la comunicación en serie a una velocidad de 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Leer el pirPin y almacenarlo como val
  val = digitalRead(pirPin);

  // Si se detecta movimiento (pirPin = HIGH), haga lo siguiente
  if (val == HIGH) {
    // Enciende el LED integrado
    digitalWrite(ledPin, HIGH);

    // Cambia el estado de movimiento a verdadero (movimiento detectado)
    if (motionState == false) {
      Serial.println("¡Movimiento detectado!");
      motionState = true;
    }
  }

  // Si no se detecta movimiento (pirPin = LOW), haga lo siguiente
  else {
    // Apaga el LED integrado
    digitalWrite(ledPin, LOW);

    // Cambia el estado de movimiento a falso (sin movimiento)
    if (motionState == true) {
      Serial.println("¡Movimiento finalizado!");
      motionState = false;
    }
  }
}
