
#include <Lora_serial.h>
Conexao conexaolora(2, 3, 9600,2);
float date_s = 10.999;
float date_s1 = 11.145;
float date_s2 = 10.55;
float date_s3 = 14;
float date_s4 = 17;
float date_s5 = 40;
float date_s6 = 40;
void setup() {
conexaolora.iniciar_setup();
}

void loop() {

  conexaolora.empacotar(String(date_s1),2);
  conexaolora.empacotar(String(date_s2),2);
  conexaolora.empacotar(String(date_s3),2);
  conexaolora.empacotar(String(date_s4),2);
  conexaolora.empacotar(String(date_s5),2);
  conexaolora.empacotar(String(date_s6),2);
  conexaolora.transmissor_c_conf();



}