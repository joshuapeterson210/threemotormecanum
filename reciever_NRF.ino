#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"
#include "DigitalIO.h"


double ReceivedMessage[] = {0,0,0};
double pwmY;
double pwmX;
double pwmR;
RF24 radio(7,8); // NRF24L01 used SPI pins + Pin 9 and 10 on the UNO
const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 


void setup(void){
Serial.begin(9600); // open the serial port at 9600 bps:
radio.begin(); // Start the NRF24L01
radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive
radio.startListening(); // Listen to see if information received
}


void loop(void){
  if (radio.available()){
    radio.read(ReceivedMessage, sizeof(ReceivedMessage)); // Read information from the NRF24L01
    pwmX = map(ReceivedMessage[0],0,1028,-255,255);
    pwmY = map(ReceivedMessage[1],0,1028,-255,255);
    pwmR = map(ReceivedMessage[2],0,1028,-255,255);
    /*Serial.println("New data set");
    Serial.println(pwmX);//x-axis 0-514-1024
    Serial.println(pwmY);//y-axis 0-508-1024
    Serial.println(pwmR);//Rotational axis  */
    
    if (pwmY < 0){
      analogWrite(11,abs(pwmY));
      analogWrite(10,0); }
    else{
      analogWrite(10,pwmY);
      analogWrite(11,0); }
    
    if (pwmX < 0){
      analogWrite(6,abs(pwmX));
      analogWrite(9,0); }
    else{
      analogWrite(9,pwmX);
      analogWrite(6,0); }
    if (pwmR < 0){
      analogWrite(3,abs(pwmR));
      analogWrite(5,0); }
    else{
      analogWrite(5,pwmR);
      analogWrite(3,0); }
   
    }
    }
    
