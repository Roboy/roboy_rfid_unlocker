#ifndef RFID_H
#define RFID_H

#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = D3; 
constexpr uint8_t SS_PIN = D8; 

class RFID{
  public: 
    RFID();
    ~RFID();

    bool checkForCard(uint8_t *uid, int &uid_length);

  private:
    MFRC522 *mfrc522;
};
#endif
