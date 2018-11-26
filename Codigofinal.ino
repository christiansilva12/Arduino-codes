#include <Servo.h>

Servo motor1;  // Motor 1
Servo motor2;  //  Motor 2
int valorA2; //variable sensor luz izquierdo, controla motor derecho
int valorA3; //variable sensor luz izquierdo, controla motor reversa
int valorA1; //variable sensor luz derecho, controla motor izquierdo
int antDer; //variable antena derecha
int antIzq; //variable antena izquierda
int sensorVal;
void setup() {
 pinMode(2, INPUT_PULLUP);
motor2.attach(4); //asignacion de motores a pines
motor1.attach(3);
pinMode(6, INPUT); // asginacion de pines como entradas
pinMode(7, INPUT);
pinMode(A2,INPUT);//FOtoR..izq
pinMode(A1,INPUT);//FOtoR..dere
pinMode(A3,INPUT);//FOtorREVErs

Serial.begin (9600);

}

void loop() {
int sensorVal = digitalRead(2);
Serial.println(sensorVal);
valorA2=analogRead(A2); //Valor señal de entrada sensor izquierdo
valorA3=analogRead(A3); //Valor señal de entrada sensor reversa
valorA1=analogRead(A1); //valor señal derecha
antIzq = digitalRead(6);  //lectura digital de pin iz
antDer = digitalRead(7);  //lectura digital de pin der
Serial.println (valorA1); //Visualizar valor señal en ordenador
 Serial.println (valorA2); // Visualizar valor señal en ordenador
  Serial.println (valorA3); //Visualizar valor señal en ordenador
   // Serial.println (antIzq);
     // Serial.println (antDer);
     // Serial.println (sensorVal);
      if (sensorVal==0){
        MovimientoA(antIzq,antDer); // definimos la funcion
                }
                if(sensorVal==1){
                  MovimientoFresis(valorA2,valorA1,valorA3);
                  }
}

void MovimientoA(float si, float ad){
    if(si==LOW){ //choque con la anten der
      motor2.writeMicroseconds(1500);//hacia atras
      motor1.writeMicroseconds(2000);
      delay(300);
      motor2.writeMicroseconds(2000);
      motor1.writeMicroseconds(2000);
      delay(300);
      motor2.writeMicroseconds(1300);
      motor1.writeMicroseconds(1300);
      }

    if (ad==LOW){ //choque con la anten izq
      motor2.writeMicroseconds(2000);//hacia atras
      motor1.writeMicroseconds(1500);
      delay(300);
      motor2.writeMicroseconds(2000);
      motor1.writeMicroseconds(2000);
      delay(300);
      motor2.writeMicroseconds(1300);
      motor1.writeMicroseconds(1300);
      }
  
 }

 void MovimientoFresis(float valorA2, float valorA1, float valorA3){
 if (valorA1>=400) {
 motor1.writeMicroseconds(1200);
 motor2.writeMicroseconds(1800);
 }
 else {
if (valorA2>=350) {
 motor1.writeMicroseconds(1800);
 motor2.writeMicroseconds(1200);
 }
 else {
  if ((valorA1>=150) && (valorA2>=150)) {
 motor1.writeMicroseconds(1000);
 motor2.writeMicroseconds(1000);
  } else {
    if (valorA3>=100) {
 motor1.writeMicroseconds(1800);
 motor2.writeMicroseconds(1800);
 }else {
 motor1.writeMicroseconds(1500);
 motor2.writeMicroseconds(1500);
 }
  }
 }
 
 }
  
}
