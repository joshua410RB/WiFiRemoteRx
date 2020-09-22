#include "WiFiRemoteRx.h"

WiFiRemoteRx rx(Serial1);

void setup() {
  // put your setup code here, to run once:
  rx.begin();
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(13,OUTPUT);
  digitalWrite(13,1);
}

void loop() {
  //enter channel number into Serial Monitor to fetch channel value
  //enter 100 to get connection status
  if(Serial.available())  { 
    int a=Serial.parseInt();
    if(a==100)  {
      Serial.println(rx.getConnectionStatus());
    }
    else  {
      Serial.println(rx.getChannel(a));
    }
  }
}
