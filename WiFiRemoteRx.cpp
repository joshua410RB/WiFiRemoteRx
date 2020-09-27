#include "WiFiRemoteRx.h"

WiFiRemoteRx::WiFiRemoteRx(HardwareSerial &s)   {
    ser=&s;
}

int WiFiRemoteRx::begin()   {
    if(ser==NULL)   {
        return -1;
    }
    else    {
        ser->begin(baudrate);
        ser->setTimeout(50);
        serialEnabled=1;
        return 1;
    }
}

void WiFiRemoteRx::setBaudRate(long baud) {
    baudrate=baud;
}

int WiFiRemoteRx::getChannel(int ch)    {
    if(ch<16&&serialEnabled)   {
        char cmd=((1<<5)+ch)&255;
        ser->write(cmd);
        while(!ser->available())    {}
        int val=ser->read();
        ser->flush();
        return val;
    }
    else    {
        return -1;
    }
}

int WiFiRemoteRx::getConnectionStatus() {
    if(!serialEnabled)  {
        return -1;
    }
    ser->write(65);
    while(!ser->available())    {}
    int status=ser->read();
    ser->flush();
    return status;
}

int WiFiRemoteRx::getNetworkStatus()    {
    if(!serialEnabled)  {
        return -1;
    }
    ser->write(66);
    while(!ser->available())    {}
    int status=ser->read();
    ser->flush();
    return status;
}