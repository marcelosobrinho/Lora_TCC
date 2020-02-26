#include <Lora_serial.h>
Conexao conexaolora(2, 3, 9600,2);

void setup() {

conexaolora.iniciar_setup();
//Serial.begin(9600);
conexaolora.iniciar_grav_arq("Teste");
}

void loop() {



}