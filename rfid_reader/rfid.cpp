#include "rfid.hpp"

RFID::RFID(){
  mfrc522 = new MFRC522(SS_PIN, RST_PIN);

  SPI.begin();                                                  // Init SPI bus
  mfrc522->PCD_Init();                                              // Init MFRC522 card
  Serial.println(F("RFID ready"));    //shows in serial that it is ready to read
}

RFID::~RFID(){
  delete mfrc522;
}

bool RFID::checkForCard(uint8_t *uid, int &uid_length){
  byte bufferATQA[2];
  byte bufferSize = sizeof(bufferATQA);
  MFRC522::StatusCode result = mfrc522->PICC_RequestA(bufferATQA, &bufferSize);
  if(!mfrc522->PICC_ReadCardSerial())
    return false;
  Serial.print("Card Detected:\t");
  uid_length = mfrc522->uid.size;
  for(int i=0; i<uid_length; i++){
    Serial.print(mfrc522->uid.uidByte[i], HEX);
    uid[i] = mfrc522->uid.uidByte[i];
  }
  Serial.println("");
  return true;
}

