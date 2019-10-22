#include <SoftwareSerial.h>
 

SoftwareSerial loraSerial(2, 3); // TX, RX

String envio;
String nomeDevice="n1";
byte dv =10; //~quantidade de dipositivos
float sensores[10]; // vetor sensores
byte i;

void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600);
   
}

void loop() {

   
 //Ja coletou todos dados dos sensores 
  Serial.println(dv);
  for (i=0; i<dv; i++){
    sensores[i]=float(i);
  }

 
//Montagem da String
 envio="";
  for (i=0; i<dv; i++){
    //Serial.println(String(sensores[i])+'-');
    envio=envio+String(sensores[i])+'-';
  }
//  Serial.println("Deu Certo"+envio);

 
// Metodo de envio 
 loraSerial.print("Pilha ->");
 loraSerial.println(nomeDevice+'-'+envio);
 delay(2000);
}
