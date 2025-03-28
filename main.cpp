#define SENSOR_ESQ A0
#define SENSOR_DIR A1
#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10

void setup() {
  pinMode(SENSOR_ESQ, INPUT);
  pinMode(SENSOR_DIR, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  int esq = digitalRead(SENSOR_ESQ);
  int dir = digitalRead(SENSOR_DIR);

  if (esq == 0 && dir == 0) {
    // Ambos sensores detectam linha (seguir em frente)
    frente();
  } else if (esq == 0 && dir == 1) {
    // Apenas o esquerdo detecta linha (vira para esquerda)
    esquerda();
  } else if (esq == 1 && dir == 0) {
    // Apenas o direito detecta linha (vira para direita)
    direita();
  } else {
    // Nenhum sensor detecta (parar ou ajuste)
    parar();
  }
}

void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void esquerda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void direita() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
