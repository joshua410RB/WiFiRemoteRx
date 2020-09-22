#ifndef WIFI_REMOTE_RX
#define WIFI_REMOTE_RX

#include "Arduino.h"

class WiFiRemoteRx{
    public:
        WiFiRemoteRx(HardwareSerial &s);
        void setBaudRate(long baud);
        int begin();
        int getChannel(int ch);
        int getConnectionStatus();
    private:
        HardwareSerial *ser=NULL;
        long baudrate=9600;
        bool serialEnabled=0;
};

#endif