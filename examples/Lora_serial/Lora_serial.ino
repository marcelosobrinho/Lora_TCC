#include <Lora_serial.h>
Conexao conexaolora(2,3,9600);


void setup() {
conexaolora.quant_disp(10);


}

void loop() {
 conexaolora.iniciar(); 
 
 

}
