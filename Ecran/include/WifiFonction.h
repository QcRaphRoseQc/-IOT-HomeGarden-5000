#pragma once
#include <WiFi.h>

class WifiFonction
{
private: 

public:
String *m_listSSID;
void listSsid();
bool connectWifi(String p_ssid , String p_password);
WifiFonction();
};


