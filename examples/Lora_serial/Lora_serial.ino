#include <Lora_serial.h>
Conexao conexaolora(2, 3, 7, 9600);
float date_s = 10.999;
float date_s1 = 11.145;
float date_s2 = 10.55;
float date_s3 = 14;
float date_s4 = 17;
float date_s5 = 40;
float date_s6 = 50;
void setup() {

}

void loop() {
  conexaolora.empacotar(date_s);
  conexaolora.empacotar(date_s1);
  conexaolora.empacotar(date_s2);
  conexaolora.empacotar(date_s3);
  conexaolora.empacotar(date_s4);
  conexaolora.empacotar(date_s5);
  conexaolora.empacotar(date_s6);
  conexaolora.iniciar_trans();



}