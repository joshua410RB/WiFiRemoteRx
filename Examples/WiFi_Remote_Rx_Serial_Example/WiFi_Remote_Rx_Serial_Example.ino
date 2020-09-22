#include "WiFiRemoteRx.h"

//this program is meant for arduinos with more than 1 serial port
//like the Mega, Due or Leonardo
//Nevertheless it (hopefully) will be a useful resource for an example
//implementation of pulling data from an Rx module

int data[16];
int connection_status;

//create an WiFi Remote Rx instance on Serial1
WiFiRemoteRx rx(Serial1);

void setup() {
  rx.begin(); //initialize the Rx

  Serial.begin(9600); //start the serial port for Serial Monitor
  Serial.setTimeout(10);

}

void loop() {
  for(int i=0;i<16;i++) { //fetch data from all 16 channels from Rx
    data[i]=rx.getChannel(i);
  }
  connection_status=rx.getConnectionStatus(); //get connection status

  Serial.print("CS: "); //print out data to Serial Monitor
  Serial.print(connection_status);
  for(int i=0;i<16;i++) {
    Serial.print(" Ch");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(data[i]);
  }
  Serial.print("\n");
  delay(1000);

}
