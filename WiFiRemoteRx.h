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
        int getNetworkStatus();
    private:
        HardwareSerial *ser=NULL;
        long baudrate=115200;
        bool serialEnabled=0;
};

#endif