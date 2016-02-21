#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio( 7, 8);
uint8_t mybuffer[32];
long mylength;
//uint8_t addresses[2][6] = {"1Node","2Node"};
uint64_t addresses[2] = { '1Node', '2Node' }; 

void setup() {
  int i;
  
  radio.begin();
  radio.setAutoAck(false);

  // Get into standby mode
  radio.startListening();
  radio.stopListening();
  radio.openWritingPipe(addresses[1]);
  mylength = 32;
  for (i = 0; i < 32; i++)
        mybuffer[i]= i*i;
}

void loop() {

  
  radio.write(mybuffer, mylength);
  delay(2000);
  
}
