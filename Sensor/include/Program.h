#include "StationMeteoWifi.h"
#include <WiFiManager.h>
#include <esp_now.h>
#include <WiFi.h>
class Program
{
private:
    StationMeteoWifi *m_stationMeteoWifi = nullptr;
public:
    Program();
    void loop();
};