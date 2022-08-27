#include <SPI.h>
#include <LoRa.h>
 
#define SS 10
#define RST 5
#define DIO0 2
 
#define TX_P 17
#define BAND 915E5
#define ENCRYPT 0x78 //Encrypt Data
 
void setup() 
{
  Serial.begin(115200);
  while (!Serial);
 
  Serial.println("LoRa Receiver");
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
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");
 
    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
 
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
