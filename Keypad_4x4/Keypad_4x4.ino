#include <Keypad.h>
#include <LiquidCrystal_I2C.h> // Libreria LCD_I2C
LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2)

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
}


void loop(){
  TECLA = teclado.getKey();
  Serial.print(TECLA);
  lcd.print(TECLA);
  if (TECLA){  
CLAVE[INDICE] = TECLA;
INDICE++;
Serial.print(TECLA);
lcd.print(TECLA);
 }
 if (INDICE ==6){
  if(!strcmp(CLAVE, CLAVE_MAESTRA))
  Serial.println(" Correcta ");
  lcd.print("Correcta");
 }
  else{
  Serial.println(" Incorrecta ");
  lcd.print("Incorrecta");
  INDICE = 0;
 }
}


//https://www.youtube.com/watch?v=9ligsi5Bgv8




