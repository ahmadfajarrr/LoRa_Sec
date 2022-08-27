#include <SPI.h>
#include <LoRa.h>
 
#define SS 10
#define RST 5
#define DIO0 2
 
#define TX_P 17
#define BAND 915E6
#define ENCRYPT 0x78 //Encrypt Data
 
int counter = 0;
 
void setup() {
  Serial.begin(115200);
  while (!Serial);
 
  Serial.println("LoRa Sender");
 
  LoRa.setTxPower(TX_P);
  LoRa.setSyncWord(ENCRYPT);
  
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(BAND)) 
  {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
 
void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
 
  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();
 
  counter++;
 
  delay(5000);
}

