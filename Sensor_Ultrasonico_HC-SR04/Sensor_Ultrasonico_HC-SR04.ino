/*Sensor Ultrasónico
F: 40Khz
Rango: 2 400 cms*/


int TRIG = 10;
int ECHO = 9;
int LED = 3;
int DURACION;
int DISTANCIA;

void setup() {
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(ECHO, LOW);
  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(200);

  if(DISTANCIA <= 20 && DISTANCIA >= 0){
    digitalWrite(LED, HIGH);
    delay(DISTANCIA * 10);
    digitalWrite(LED, LOW);
  }
}
