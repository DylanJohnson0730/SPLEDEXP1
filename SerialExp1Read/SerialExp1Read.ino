#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio (7, 8);
long mylength;
uint8_t mybuffer[32];

void setup() {
  int i;
  radio.begin();
  radio.setAutoAck(false);
  radio.startListening();
  radio.stopListening();

}

void loop() {
  radio.read(mybuffer, mylength);
  delau(2000);

}
