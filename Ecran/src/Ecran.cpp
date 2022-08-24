
//  Le code es un peut compliquer c'etais le code auto generated par GUISlice Builder , je l'ai modifié pour que ce soit plus simple
//  J'ai essayer de tous mettre les declarations dans le header mais j'ai pas pu faire fonctionner et j'ai manqué de temps
//  Et avec plus de temps j'aurais separer le code en plusieurs classes.
//  Cela vas etre corrige pour le HOMEGARDEN 6000

//<App !Start!>
// FILE: [arduino.ino]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include
// ------------------------------------------------

#include "Ecran.h"
#include "GUI.h"

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef *m_pElemInTxt1 = NULL;
gslc_tsElemRef *m_pElemInTxt2 = NULL;
gslc_tsElemRef *m_pElemInTxt4 = NULL;
gslc_tsElemRef *m_pElemInTxt5 = NULL;
gslc_tsElemRef *m_pElemInTxt6 = NULL;
gslc_tsElemRef *m_pElemInTxt7 = NULL;
gslc_tsElemRef *m_pElemInTxt8 = NULL;
gslc_tsElemRef *m_pElemInTxt9 = NULL;
gslc_tsElemRef *m_pElemInTxt10 = NULL;
gslc_tsElemRef *m_pElemInTxt11 = NULL;
gslc_tsElemRef *m_pElemInTxt12 = NULL;
gslc_tsElemRef *m_pElemInTxt1_3 = NULL;
gslc_tsElemRef *m_pElemXRingGauge5 = NULL;
gslc_tsElemRef *m_pElemListbox1 = NULL;
gslc_tsElemRef *m_pListSlider1 = NULL;
gslc_tsElemRef *m_pElemKeyPadAlpha = NULL;
gslc_tsElemRef *m_pElemXRingGauge5_6 = NULL;
gslc_tsElemRef *m_pElemXRingGauge5_7 = NULL;
//<Save_References !End!>

// ------------------------------------------------

// ESPNOW variables
// definir le mac adresse du ESP32(SENSOR)
uint8_t broadcastAddress[] = {0xE0, 0xE2, 0xE6, 0x0D, 0x51, 0xE8};

// Structure du Message pour ESPNOW
typedef struct struct_message
{
    char ssid[55];
    char password[55];
    char broker[55];
} struct_message;

struct_message myData;

esp_now_peer_info_t peerInfo;
// ------------------------------------------------

Ecran::Ecran()
{

    this->m_wifiFonction = new WifiFonction();
    this->m_wifiFonction->listSsid();
}

void ListboxLoad(gslc_tsElemRef *pElemRef, String *p_listSSID)
{
    for (int i = 0; i < p_listSSID->length(); i++)
    {
        gslc_ElemXListboxAddItem(&m_gui, m_pElemListbox1, p_listSSID[i].c_str());
    }
}

void espNow(char *p_ssid, char *p_password, char *p_broker)
{
    strcpy(myData.ssid, p_ssid);
    strcpy(myData.password, p_password);
    strcpy(myData.broker, p_broker);
    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));
}

void connectWifi()
{

    char *p_ssid_name = gslc_ElemGetTxtStr(&m_gui, m_pElemInTxt2);
    char *p_ssid_pass = gslc_ElemGetTxtStr(&m_gui, m_pElemInTxt1);
    char *p_broker = gslc_ElemGetTxtStr(&m_gui, m_pElemInTxt1_3);

    // Call methode pour connecter au ESP32 avec ESPNOW
    espNow(p_ssid_name, p_ssid_pass, p_broker);

    // Apres on se connecte au wifi
    // Sa freeze l'ecran quand on essaie de se connecter au wifi j'ai pas eu le temps de le faire async / nonblocking avec des millis
    // L'ecran continue normalement une fois connecter au wifi
    connectionStateWifi = m_wifiFonction->connectWifi(p_ssid_name, p_ssid_pass);

    if (connectionStateWifi == false)
    {
        gslc_ElemSetTxtCol(&m_gui, m_pElemInTxt4, GSLC_COL_RED);
        gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt4, "Wifi Erreur");
    }
    else if (isEspNow == false)
    {
        gslc_ElemSetTxtCol(&m_gui, m_pElemInTxt4, GSLC_COL_RED);
        gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt4, "Sensor Erreur");
    }
    else if (connectionStateMQTT == false)
    {
        gslc_ElemSetTxtCol(&m_gui, m_pElemInTxt4, GSLC_COL_YELLOW);
        gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt4, "En attente HomeAssistant");
    }
}

bool mqttConnect() // Fonction pour se connecter au serveur MQTT
{
    char *p_broker = gslc_ElemGetTxtStr(&m_gui, m_pElemInTxt1_3);

    client.setServer(p_broker, 1883);
    client.setCallback(callback);

    Serial.print("Connection vers ");
    Serial.println(p_broker);
    if (client.connect("", brokerUser, brokerPass))
    {
        Serial.print("\nConnecte vers ");
        Serial.println(p_broker);
        connectionStateMQTT = true;
        client.subscribe("esp32/temperature");
        client.subscribe("esp32/humidite");
        client.subscribe("esp32/pression");
    }
    else
    {
        Serial.println("\nConnection au serveur Home Assistant impossible");
        gslc_ElemSetTxtCol(&m_gui, m_pElemInTxt4, GSLC_COL_RED);
        gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt4, "Erreur Connection Home Assistant");
        connectionStateMQTT = false;
    }

    //Print l'etat des connexions
    Serial.println("MQTT : " + String(connectionStateMQTT));
    Serial.println("Wifi : " + String(connectionStateWifi));
    Serial.println("ESPNOW : " + String(isEspNow));

    // Si tout les connection sont ok on vas a la page Sensor HomeAssistant / Prediction
    if (connectionStateMQTT == true && connectionStateWifi == true && isEspNow == true)
    {
        afficherMeteoQuebec();
        gslc_SetPageCur(&m_gui, E_PG3);
    }
    else
    {
        gslc_SetPageCur(&m_gui, E_PG2);
    }

    return connectionStateMQTT;
}

void callback(char *topic, byte *payload, unsigned int length) // Fonction CallBack pour print un message recu
{

    for (int i = 0; i < length; i++)
    {

        // Pour chaque Topic on print le message recu
        if (String(topic) == "esp32/temperature")
        {
            String temperature = String((char)payload[i]);
            // on affiche la temperature
            gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt5, (char *)payload);

            float temp = temperature.toFloat();
            gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGauge5_6, temp);
        }
        else if (String(topic) == "esp32/humidite")
        {
            String humidite = String((char)payload[i]);
            // on affiche l'humidite
            gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt7, (char *)payload);

            float humid = humidite.toFloat();
            gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGauge5_7, humid);
        }
        else if (String(topic) == "esp32/pression")
        {
            String pression = String((char)payload[i]);
            // on affiche la pression
            gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt6, (char *)payload);

            float press = pression.toFloat();
            gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGauge5, press);
        }
    }
};

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
    if (status == ESP_NOW_SEND_SUCCESS)
    {
        Serial.println("Sent with success");
        isEspNow = true;
    }
    else
    {
        Serial.println("Error sending the data");
        gslc_ElemSetTxtCol(&m_gui, m_pElemInTxt4, GSLC_COL_RED);
        gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt4, "Erreur Sensor");
        isEspNow = false;
    }
}


String obtenirMeteoQuebec()
{
  String res = "";
  if (WiFi.status() == WL_CONNECTED)
  {
    String url = "https://weatherdbi.herokuapp.com/data/weather/Quebec";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();

    if (codeStatut != 200)
    {
      Serial.println(HTTPClient::errorToString(codeStatut));
    }
    else
    {
      res = httpClient.getString();
    }
  }
  else
  {
    Serial.println("Non connecté au WiFi !");
  }

  return res;
}

void afficherInformationMeteoAPartirJSON(const String &json)
{
  DynamicJsonDocument doc(4096);
  DeserializationError error = deserializeJson(doc, json);

  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  int ventkm = doc["currentConditions"]["wind"]["km"];
  int temperatureActuelle = doc["currentConditions"]["temp"]["c"];
  
  char *vent = new char[10];
  sprintf(vent, "%d", ventkm);
  char *temperature = new char[10];
  sprintf(temperature, "%d", temperatureActuelle);

  gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt8, temperature);
  gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt9, (const char *)doc["currentConditions"]["precip"]);
  gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt10, vent);
  gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt11, (const char *)doc["currentConditions"]["comment"]);
}

void afficherMeteoQuebec()
{
  String json = obtenirMeteoQuebec();
  if (json != "")
  {
    afficherInformationMeteoAPartirJSON(json);
  }
  else
  {
    Serial.println("Erreur d'obtention de la météo");
  }
}

// Common Button callback
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY)
{
    // Typecast the parameters to match the GUI and element types
    gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
    gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
    gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

    if (eTouch == GSLC_TOUCH_UP_IN)
    {
        // From the element's ID we can determine which button was pressed.
        switch (pElem->nId)
        {
            //<Button Enums !Start!>
        case E_ELEM_BTN1:
            gslc_SetPageCur(&m_gui, E_PG2);

            break;
        case E_ELEM_TEXTINPUT1:
            // Clicked on edit field, so show popup box and associate with this text field
            gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, m_pElemInTxt1);

            break;
        case E_ELEM_TEXTINPUT2:
            // Clicked on edit field, so show popup box and associate with this text field
            gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, m_pElemInTxt2);
            break;
        case E_ELEM_TEXTINPUT3:
            // Clicked on edit field, so show popup box and associate with this text field
            gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, m_pElemInTxt1_3);
            break;
        case E_ELEM_BTN2:
            // change m_pElemInTxt

            gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt4, "En cours de connexion");

            connectWifi();

            break;

        default:
            break;
        }
    }
    return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
// KeyPad Input Ready callback
bool CbKeypad(void *pvGui, void *pvElemRef, int16_t nState, void *pvData)
{
    gslc_tsGui *pGui = (gslc_tsGui *)pvGui;
    gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
    gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

    // From the pvData we can get the ID element that is ready.
    int16_t nTargetElemId = gslc_ElemXKeyPadDataTargetIdGet(pGui, pvData);
    if (nState == XKEYPAD_CB_STATE_DONE)
    {
        // User clicked on Enter to leave popup
        // - If we have a popup active, pass the return value directly to
        //   the corresponding value field
        switch (nTargetElemId)
        {
            //<Keypad Enums !Start!>
        case E_ELEM_TEXTINPUT1:
            gslc_ElemXKeyPadInputGet(pGui, m_pElemInTxt1, pvData);
            gslc_PopupHide(&m_gui);
            break;

        case E_ELEM_TEXTINPUT2:
            gslc_ElemXKeyPadInputGet(pGui, m_pElemInTxt2, pvData);
            gslc_PopupHide(&m_gui);
            break;

        case E_ELEM_TEXTINPUT3:
            gslc_ElemXKeyPadInputGet(pGui, m_pElemInTxt1_3, pvData);
            gslc_PopupHide(&m_gui);
            break;
            //<Keypad Enums !End!>
        default:
            break;
        }
    }
    else if (nState == XKEYPAD_CB_STATE_CANCEL)
    {
        // User escaped from popup, so don't update values
        gslc_PopupHide(&m_gui);
    }
    return true;
}
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
bool CbListbox(void *pvGui, void *pvElemRef, int16_t nSelId)
{

    gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
    gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
    gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
    char acTxt[MAX_STR + 1];

    if (pElemRef == NULL)
    {
        return false;
    }

    // From the element's ID we can determine which listbox was active.
    switch (pElem->nId)
    {
        //<Listbox Enums !Start!>
    case E_ELEM_LISTBOX1:
        if (nSelId != XLISTBOX_SEL_NONE)
        {
            gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
            String ssid = acTxt;
            int pos = ssid.indexOf(" ");
            String ssid_name = ssid.substring(0, pos);
            // Serial.println(ssid_name);

            gslc_ElemSetTxtStr(&m_gui, m_pElemInTxt2, ssid_name.c_str());
        }
        break;

        //<Listbox Enums !End!>
    default:
        break;
    }
    return true;
}
//<Draw Callback !Start!>
//<Draw Callback !End!>

// Callback function for when a slider's position has been updated
bool CbSlidePos(void *pvGui, void *pvElemRef, int16_t nPos)
{
    gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
    gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
    gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
    int16_t nVal;
    gslc_tsElemRef *pElemRefTmp = NULL;

    // From the element's ID we can determine which slider was updated.
    switch (pElem->nId)
    {
    case E_LISTSCROLL1:
        // Fetch the slider position
        nVal = gslc_ElemXSliderGetPos(pGui, pElemRef);
        // Update the textbox scroll position
        pElemRefTmp = gslc_PageFindElemById(pGui, E_PG2, E_ELEM_LISTBOX1);

        gslc_ElemXListboxSetScrollPos(pGui, pElemRefTmp, nVal);
        break;
    default:
        break;
    }

    return true;
}
//<Tick Callback !Start!>
//<Tick Callback !End!>

void espNowSetup()
{

    // Code trouve dans la cocumentation ESPNOW
    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);

    // Init ESP-NOW
    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Once ESPNow is successfully Init, we will register for Send CB to
    // get the status of Trasnmitted packet
    esp_now_register_send_cb(OnDataSent);

    // Register peer
    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    // Add peer
    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        Serial.println("Failed to add peer");
        return;
    }
}

void Ecran::setup()
{
    // ------------------------------------------------
    // Initialize
    // ------------------------------------------------
    Serial.begin(115200);

    // Initialisation de ESPNOW
    espNowSetup();

    // delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

    // ------------------------------------------------
    // Create graphic elements
    // ------------------------------------------------
    InitGUIslice_gen();

    ListboxLoad(m_pElemListbox1, m_wifiFonction->m_listSSID);
}

// -----------------------------------
// Main event loop
// -----------------------------------
void Ecran::loop()
{
    //une fois connecter au wifi , au espNow et que le pubsub est pas connecter, on spam la fonction de connection et apres on loop le pubsub
    if (connectionStateWifi == true && isEspNow == true)
    {
        if (!client.connected())
        {
            mqttConnect();
        }
        client.loop();
    }

    // ------------------------------------------------
    // Update GUI Elements
    // ------------------------------------------------

    // TODO - Add update code for any text, gauges, or sliders

    // ------------------------------------------------
    // Periodically call GUIslice update function
    // ------------------------------------------------
    gslc_Update(&m_gui);
}