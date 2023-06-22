#include "SoftwareSerial.h"
#define motorATras 6
#define motorAFrente 5
#define motorBTras 9
#define motorBFrente 10
#define motorBEnablePin 11
#define motorAEnablePin 7
#define TX 4// HC-05 BLUETOOTH MODULE'S TX PORT GOES HERE
#define RX 3// HC-05 BLUETOOTH MODULE'S RX PORT GOES HERE

SoftwareSerial bluetooth(TX, RX);

void setup(){
    Serial.begin(9600);
    bluetooth.begin(9600);
    digitalWrite(motorAEnablePin, HIGH);
    digitalWrite(motorBEnablePin, HIGH);
}

void loop(){
  if(bluetooth.available()> 0){
        Serial.println(bluetooth.read());
        }
          switch (bluetooth.read()) {
        case 'W':
          digitalWrite(motorATras, LOW);
          digitalWrite(motorAFrente, HIGH);
          digitalWrite(motorBTras, LOW);
          digitalWrite(motorBFrente, HIGH);
          //Serial.println("FRENTE");
          break;
        case 'A':
          digitalWrite(motorATras, HIGH);
          digitalWrite(motorAFrente, LOW);
          digitalWrite(motorBTras, LOW);
          digitalWrite(motorBFrente, HIGH);
          //Serial.println("ESQUERDA");
          break;
        case 'D':
          digitalWrite(motorATras, LOW);
          digitalWrite(motorAFrente, HIGH);
          digitalWrite(motorBTras, HIGH);
          digitalWrite(motorBFrente, LOW);
          //Serial.println("DIREITA");
          break;
        case 'S':
          digitalWrite(motorATras, HIGH);
          digitalWrite(motorAFrente, LOW);
          digitalWrite(motorBTras, HIGH);
          digitalWrite(motorBFrente, LOW);
          //Serial.println("TRAS");
          break;
        case '0':
          digitalWrite(motorATras, LOW);
          digitalWrite(motorAFrente, LOW);
          digitalWrite(motorBTras, LOW);
          digitalWrite(motorBFrente, LOW);
         }
}
