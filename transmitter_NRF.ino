
#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

RF24 radio(9,10); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO
const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 
double SentMessage[] = {0,0,0}; // Used to store value before being sent through the NRF24L01


void setup(void){
  Serial.begin(9600); // open the serial port at 9600 bps:
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
}


void loop(void){
  SentMessage[0] = analogRead(1);//x-axis
  SentMessage[1] = analogRead(0);//y-axis
  SentMessage[2] = analogRead(2);//Rotational axis
  radio.write(SentMessage, sizeof(SentMessage)); // Send value through NRF24L01
}
