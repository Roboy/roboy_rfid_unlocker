#include "rfid.hpp"
#include "wirelessLove.hpp"

RFID *rfid;
WirelessLove *wifi;

const char* ssid = "roboy";
const char* passwd = "wiihackroboy";

const char* key = "The path of the righteous man is beset on all sides by the inequities of the "
                  "selfish and the tyranny of evil men. Blessed is he who, in the name of "
                  "charity and good will, shepherds the weak through the valley of the darkness. "
                  "For he is truly his brother's keeper and the finder of lost children. And I "
                  "will strike down upon thee with great vengeance and furious anger those who "
                  "attempt to poison and destroy my brothers. And you will know I am the Lord "
                  "when I lay my vengeance upon you\0";

//*****************************************************************************************//
void setup() {
  Serial.begin(115200);                                           // Initialize serial communications with the PC
  rfid = new RFID;
  IPAddress broadcastIP(129,187,142,26);
  wifi = new  WirelessLove(ssid, passwd, broadcastIP);
}

//*****************************************************************************************//
void loop() {
  uint8_t uid[10];
  int uid_length;
  if(rfid->checkForCard(uid, uid_length)){
    char output[strlen(key)];
    int j = 0;
    for (int i=0; i<strlen(key); i++)
    {
      output[i] = key[i] ^ uid[j];
      j++;
      if(j == uid_length)
        j = 0;
    }
    wifi->broadcast_send((uint8_t*)output, strlen(key));
  }
  delay(1000);
}
//*****************************************************************************************//
