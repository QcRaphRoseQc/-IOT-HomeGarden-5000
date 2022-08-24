#include <Program.h>

// Variable ne pouvant être dans .h puisqu'ils doivent être accessible par la methode OnDataRecv pour esp-now
bool informationRecu = false;
char *SSIDPortail;
char *motPasseAPPortail;
char *broker;

typedef struct struct_message
{
    char ssid[55];
    char password[55];
    char broker[55];
} struct_message;

struct_message myData;
// -------------------------------

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
    Serial.println();
    memcpy(&myData, incomingData, sizeof(myData));
    Serial.print("Bytes received: ");
    Serial.println(len);
    Serial.print("ssid: ");
    Serial.println(myData.ssid);
    Serial.print("Password: ");
    Serial.println(myData.password);
    Serial.print("Broker: ");
    Serial.println(myData.broker);
    Serial.println();

    SSIDPortail = myData.ssid;
    motPasseAPPortail = myData.password;
    broker = myData.broker;
    informationRecu = true;
}

Program::Program()
{
    Serial.begin(115200);
    // Mettre le péripherique en mode wi-fi station
    WiFi.mode(WIFI_STA);

    // Initialiser esp-now
    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // si initialisé, on enregistre la fonction qui recevra les données
    esp_now_register_recv_cb(OnDataRecv);
}
void Program::loop()
{
    if (informationRecu)
    {
        if (this->m_stationMeteoWifi == nullptr)
        {
            Serial.println("BEEN HERE");
            this->m_stationMeteoWifi = new StationMeteoWifi(SSIDPortail, motPasseAPPortail, broker);
        }
        this->m_stationMeteoWifi->loop();
    }
}