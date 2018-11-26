#include <NECIRrcv.h>


#include <Servo.h>
#include <Arduino.h>
#include <NECIRrcv.h>
#define IRPIN 10   // pin al que conectamos el receptor de IR
static int aux = 1;
NECIRrcv ir(IRPIN) ; // Asignamos como receptor a "IRPIN" 
Servo motor1;  // Motores lado izquierdo
Servo motor2;  // Motores lado derecho
const int LED=8;
int baller = 12;
int conta;
int conta2;
void setup()
{
  Serial.begin(9600) ;
  Serial.println("NEC IR codigo recepcion") ;
  ir.begin() ;
  motor1.attach(5);  // Motores lado derecho
  motor2.attach(6);  // Motores lado izquierdo
  pinMode(LED,OUTPUT);
  pinMode(baller, OUTPUT);
 
}
void loop()
{ //Lectura de fotoceldas
    long resis=analogRead(A2);
    long resis1=analogRead(A3);
  //
  
  
  // Decision Fotoceldas
  if (resis<=200 ){
            conta=1;
    }
  if (resis1<=200){
             conta2=1;
    }
  
  if (conta2==1 && conta==1){
       motor1.writeMicroseconds(1500); //1500 stop && 1000 fw && 2000 bw
       motor2.writeMicroseconds(1500);
       digitalWrite(LED,HIGH);
       digitalWrite(baller,HIGH);
       delay(100000);
    }  
    
  if (conta==1){
       digitalWrite(LED,HIGH);
      }
  if (conta2==1){
       digitalWrite(baller,HIGH);
      }
      
  // lectura del codigo IR
  unsigned long ircode ; //Variable que almacena el valor IR leido
     while (ir.available()) { 
     ircode = ir.read() ;  // Asignamos la lectura a la variable "ircode"
     Serial.println(ircode) ; 
      }
  //
          // Lectura de valor de las fotoresistencia
          //Serial.println(resis);
          //Serial.println(resis1);
          //
  direccion(ircode);
}


void direccion(unsigned long dir)
{
  if (dir==3810328320){ //freno
    motor1.writeMicroseconds(1500); //1500 stop && 1000 fw && 2000 bw
  motor2.writeMicroseconds(1500); 
     }
  if (dir==3877175040){ //moverme adelante
    motor1.writeMicroseconds(1000); //1500 stop && 1000 fw && 2000 bw
  motor2.writeMicroseconds(1000); 
     }
  if (dir==2907897600){ //moverme atras
    motor1.writeMicroseconds(2000); //1500 stop && 1000 fw && 2000 bw
  motor2.writeMicroseconds(2000);  
    }
  if (dir==4144561920){ //moverme izquierda
    motor1.writeMicroseconds(1000); //1500 stop && 1000 fw && 2000 bw
  motor2.writeMicroseconds(1500);  
    }
  if (dir==2774204160){ //moverme derecha
    motor1.writeMicroseconds(1500); //1500 stop && 1000 fw && 2000 bw
  motor2.writeMicroseconds(1000);  
    }
  
  }
