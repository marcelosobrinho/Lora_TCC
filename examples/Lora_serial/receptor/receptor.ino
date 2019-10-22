#include <SoftwareSerial.h>
 

 
SoftwareSerial loraSerial(2, 3); // TX, RX
 
void setup() {

  Serial.begin(9600);
  loraSerial.begin(9600);  
}
 
void loop() { 
  
  if(loraSerial.available() > 1){
    Serial.print("recebendo...");
    delay(100);
    Serial.print("......");
    delay(100);
    Serial.print("............");
    delay(100);
    Serial.println("....................ok");
    delay(50);
    String input = loraSerial.readString();
    Serial.println(input);  
    delay(100);

  }else{
    Serial.println("FALHA!!");
     delay(50);
  }
 
}
