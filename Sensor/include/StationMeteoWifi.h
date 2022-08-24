#include <WiFiManager.h>
#include <uri/UriRegex.h>
#include <PubSubClient.h>
#include <Adafruit_BME280.h>
class StationMeteoWifi
{
private:
    WiFiClient m_espClient;
    PubSubClient m_client;
    IPAddress m_adresseIPPortail;
    IPAddress m_passerellePortail;
    IPAddress m_masqueReseauPortail;
    Adafruit_BME280 m_bme;

    char *m_SSIDPortail;
    char *m_motPasseAPPortail;
    char *m_broker;
    const char *m_brokerUser = "mqtt-user";
    const char *m_brokerPass = "admin1234";
    int m_tempDuneBoucle = 2000; // en milliseconde
    unsigned long m_tempPresent = 0;

    //Variable pour les données du BME
    float m_pression;
    float m_temperature;
    float m_humidite;

    char m_tempString[8];
    char m_pressionString[8];
    char m_humiditeString[8];

    const char *m_topic_temperature = "esp32/temperature";
    const char *m_topic_humidite = "esp32/humidite";
    const char *m_topic_pression = "esp32/pression";
    const char *m_topic_altitude = "esp32/altitude";

    bool m_temperaturePublie = false;
    bool m_humiditePublie = false;
    bool m_pressionPublie = false;

    //------------------------------------
    void demarrerReseau();
    
    void connexionMQTT();
    void envoyerDonneesBME();
public:
    StationMeteoWifi(char *p_SSID, char *p_password, char *p_broker);
    void loop();
};