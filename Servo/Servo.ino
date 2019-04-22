#include <Servo.h>

Servo servo1;

int PINSERVO = 2;
//os valores de pulso MAX y MIN, estan expresados en microsegundos
int PULSOMIN = 1000;
int PULSOMAX = 2000;

void setup() {
servo1.attach(PINSERVO, PULSOMIN, PULSOMAX); 

}
//La funcion attach, requiere que los valores esten expresados en microsegundos



void loop() {
 servo1.write(0);
 delay(5000);
 servo1.write(180);
 delay(5000);

}
