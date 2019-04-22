//Alarma IT-ST

/*
 Board I2C / TWI pins
Uno       =   A4 (SDA), A5 (SCL)
Mega2560  =   20 (SDA), 21 (SCL)
Leonardo  =   2 (SDA), 3 (SCL)
Due       =   20 (SDA), 21 (SCL), SDA1, SCL1

esta configuracion de estos pines se encuentran dentro de la librería "wire" mas info: https://www.arduino.cc/en/Reference/Wire
 */

#include <LiquidCrystal_I2C.h> // Libreria LCD_I2C
LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2)
#include <Keypad.h>

/* Pines Keypad:
F1: 6
F2: 7
F3: 8
F4: 9
C1: 2
C2: 3
C3: 4
C4: 5*/
const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys [FILAS] [COLUMNAS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'},
};

byte pinesColumnas [COLUMNAS] = {2,3,4,5};
byte pinesFilas [FILAS] = {6,7,8,9};


Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

char TECLA;
char CLAVE[7];
char CLAVE_MAESTRA[7] = "123456";
byte INDICE = 0;

/*int Z1led = 6;
int Z2led = 7;
int Z3led = 8;
int Z4led = 9;
int Z5led = 10;
int Z6led = 11;
int Z7led = 12;
int Z8led = 13;*/

int multiplexE = 10;
int multiplexS2 = 11;
int multiplexS1 = 12;
int multiplexS0 = 13;
int Bell = 2;
int Z1, Z2, Z3, Z4, Z5, Z6, Z7, Z8 = false;
//int Z1, Z2, Z3, Z4, Z5, Z6, Z7, Z8 = A0;
int Zonas = 0;
int Estado = (Z1, Z2, Z3, Z4, Z5, Z6, Z7, Z8);
//Z1=127, Z2=254, Z3=381, Z4=508, Z5=635, Z6=762, Z7=889 y Z8=1016

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
 lcd.setCursor(8,0);
  lcd.print("Alarma");
  lcd.setCursor (8,1);
  lcd.print("IT-ST");
  delay(2000);
  lcd.clear();
  
  /*Serial.begin(3600);
  pinMode(Z1led, OUTPUT);
  pinMode(Z2led, OUTPUT);
  pinMode(Z3led, OUTPUT);
  pinMode(Z4led, OUTPUT);
  pinMode(Z5led, OUTPUT);
  pinMode(Z6led, OUTPUT);
  pinMode(Z7led, OUTPUT);
  pinMode(Z8led, OUTPUT);
  pinMode(Bell, OUTPUT);*/
  pinMode(multiplexE, OUTPUT);
  pinMode(multiplexS2, OUTPUT);
  pinMode(multiplexS1, OUTPUT);
  pinMode(multiplexS0, OUTPUT);
  pinMode(Bell, OUTPUT);

  
}

void loop() {

 TECLA = teclado.getKey();
  Serial.print(TECLA);
  if (TECLA){  
CLAVE[INDICE] = TECLA;
INDICE++;
Serial.print(TECLA);

 }
 if (INDICE ==6){
  if(!strcmp(CLAVE, CLAVE_MAESTRA))
  Serial.println(" Correcta ");
  else
  Serial.println(" Incorrecta ");
  INDICE = 0;
 }
  
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);

    
    lcd.setCursor(0,0);
    lcd.print("IT-ST");
    lcd.clear();
  
  true == HIGH;
  false == LOW;
  digitalWrite(multiplexE, LOW);
  digitalWrite(multiplexS2, LOW);
  digitalWrite(multiplexS1, LOW);
  digitalWrite(multiplexS0, LOW);
  analogRead(Zonas);
  if (Zonas = HIGH){
    Z1 == true;
    //digitalWrite(Z1led, HIGH);
    Serial.println("Zona 1");
    lcd.setCursor(0,3);
    lcd.print("Zona 1");
  }
  delay(1000);
  lcd.clear();
  digitalWrite(multiplexE, HIGH);
  delay(200);
    digitalWrite(multiplexE, LOW);
  digitalWrite(multiplexS2, LOW);
  digitalWrite(multiplexS1, LOW);
  digitalWrite(multiplexS0, HIGH);
  analogRead(Zonas);
  if (Zonas = HIGH){
    Z2 == true;
    //digitalWrite(Z2led, HIGH);
    Serial.println("Zona 2");
    lcd.setCursor(0,3);
    lcd.print("Zona 2");
  }
  delay(1000);
  lcd.clear();
  digitalWrite(multiplexE, HIGH);
  delay(200);
  digitalWrite(multiplexE, LOW);
  digitalWrite(multiplexS2, LOW);
  digitalWrite(multiplexS1, HIGH);
  digitalWrite(multiplexS0, LOW);
 analogRead(Zonas);
 if (Zonas = HIGH){
  Z3 == true;
  //digitalWrite(Z3led, HIGH);
  Serial.println("Zona 3");
  lcd.setCursor(0,3);
  lcd.print("Zona 3");
  }
  delay(1000);
  lcd.clear();
  digitalWrite(multiplexE, HIGH);
  delay(200);
  digitalWrite(multiplexE, LOW);
  digitalWrite(multiplexS2, LOW);
  digitalWrite(multiplexS1, HIGH);
  digitalWrite(multiplexS0, HIGH);
 analogRead(Zonas);
 if (Zonas = HIGH);{
  Z4 == true;
  //digitalWrite(Z4led, HIGH);
  Serial.println("Zona 4");
  lcd.setCursor(0,3);
  lcd.print("Zona 4");
 }
 delay(1000);
 lcd.clear();
 digitalWrite(multiplexE, HIGH);
 delay(200);
  digitalWrite(multiplexE, LOW);
  digitalWrite(multiplexS2, HIGH);
  digitalWrite(multiplexS1, LOW);
  digitalWrite(multiplexS0, LOW);
 analogRead(Zonas);
 if (Zonas = HIGH){
  Z5 == true;
  //digitalWrite(Z5led, HIGH);
  Serial.println("Zona 5");
  lcd.setCursor(0,3);
  lcd.print("Zona 5");
 }
 delay(1000);
 lcd.clear();
 digitalWrite(multiplexE, HIGH);
 delay(200);
  digitalWrite(multiplexE, LOW);
  digitalWrite(multiplexS2, HIGH);
  digitalWrite(multiplexS1, LOW);
  digitalWrite(multiplexS0, HIGH);
 analogRead(Zonas);
 if (Zonas = HIGH){
  Z6 == true;
  //digitalWrite(Z6led, HIGH);
  Serial.println("Zona 6");
  lcd.setCursor(0,3);
  lcd.print("Zona 6");
 }
 delay(1000);
 lcd.clear();
 digitalWrite(multiplexE, HIGH);
 delay(200);
  digitalWrite(multiplexE, LOW);
  digitalWrite(multiplexS2, HIGH);
  digitalWrite(multiplexS1, HIGH);
  digitalWrite(multiplexS0, LOW);
 analogRead(Zonas);
 if (Zonas = HIGH){
  Z7 == true;
  //digitalWrite(Z7led, HIGH);
  Serial.println("Zona 7");
  lcd.setCursor(0,3);
  lcd.print("Zona 7");
 }
 delay(1000);
 lcd.clear();
 digitalWrite(multiplexE, HIGH);
 delay(200);
  digitalWrite(multiplexE, LOW);
  digitalWrite(multiplexS2, HIGH);
  digitalWrite(multiplexS1, HIGH);
  digitalWrite(multiplexS0, HIGH);
 analogRead(Zonas);
 if (Zonas = HIGH){
  Z8 == true;
  //digitalWrite(Z8led, HIGH);
  Serial.println("Zona 8");
  lcd.setCursor(0,3);
  lcd.print("Zona 8");
 }
 delay(1000);
 lcd.clear();
 digitalWrite(multiplexE, HIGH);
 
 if (Estado == true){
  digitalWrite(Bell, HIGH);
  Serial.print("Disparo de Alarma");
  lcd.setCursor(0,0);
  lcd.print("Disparo de Alarma");
  delay(10000); 
 }
 else {
  Serial.print("OK!");
  lcd.setCursor(8,0);
  lcd.print("OK");
  delay(2000);
 }
}



