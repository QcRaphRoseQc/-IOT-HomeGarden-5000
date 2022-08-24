#include "WifiFonction.h"

// ctor
WifiFonction::WifiFonction()
{
}

void WifiFonction::listSsid()
{

  Serial.println("scan network");

  int n = WiFi.scanNetworks();
  Serial.println("scan fini");
  if (n == 0)
  {
    Serial.println("aucun reseau trouve");
  }
  else
  {
    this->m_listSSID = new String[n];
    Serial.print(n);
    Serial.println(" networks trouve");
    for (int i = 0; i < n; ++i)
    {
      m_listSSID[i] = WiFi.SSID(i);
    }
  }

  Serial.println("");
}

bool WifiFonction::connectWifi(String p_ssid, String p_password)
{

  bool connected = false;

  const uint8_t nbEssaisMaximum = 30;
  uint8_t nbEssais = 0;

  WiFi.begin(p_ssid.c_str(), p_password.c_str());

  Serial.print("Connexion : ");
  while (nbEssais < nbEssaisMaximum && WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    nbEssais++;
  }
  Serial.println("");

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print("Connecté au réseau WiFi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");
    connected = true;
  }
  else
  {
    Serial.println("Impossible de se connecter au réseau WiFi");
    Serial.println("");
    connected = false;
  }
  return connected;
}
