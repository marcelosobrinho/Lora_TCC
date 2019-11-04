#include <Lora_serial.h>
Conexao conexaolora(2, 3, 5, 9600);
double date_s = 10.999;
double date_s1 = 11.145;
double date_s2 = 10.55;
double date_s3 = 14;
double date_s4 = 17;
double date_s5 = 40;
double date_s6 = 40;
void setup() {

}

void loop() {

  conexaolora.empacotar(date_s1);
  conexaolora.empacotar(date_s2);
  conexaolora.empacotar(date_s3);
  conexaolora.empacotar(date_s4);
  conexaolora.empacotar(date_s5);
  conexaolora.empacotar(date_s6);
  conexaolora.iniciar_trans();



}