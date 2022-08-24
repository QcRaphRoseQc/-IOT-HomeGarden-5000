#include <StationMeteoWifi.h>
StationMeteoWifi::StationMeteoWifi(char *p_SSID, char *p_password, char *p_broker) : m_client(m_espClient)
{
  this->m_SSIDPortail = p_SSID;
  this->m_motPasseAPPortail = p_password;
  this->m_broker = p_broker;
  this->demarrerReseau();
  this->m_client.setServer(this->m_broker, 1883);
}
void StationMeteoWifi::loop()
{
  if (!m_client.connected())
  {
    this->connexionMQTT();
  }

  if (millis() > this->m_tempPresent + this->m_tempDuneBoucle)
  {
    this->m_tempPresent = millis();
    this->envoyerDonneesBME();
  }
};
void StationMeteoWifi::envoyerDonneesBME()
{
  this->m_bme.begin(0x76);

  this->m_temperature = this->m_bme.readTemperature();
  this->m_humidite = this->m_bme.readHumidity();
  this->m_pression = this->m_bme.readPressure() / 100.0F;

  dtostrf(this->m_temperature, 1, 2, this->m_tempString);
  dtostrf(this->m_humidite, 1, 2, this->m_humiditeString);
  dtostrf(this->m_pression, 1, 2, this->m_pressionString);

  this->m_temperaturePublie = m_client.publish(m_topic_temperature, m_tempString);
  this->m_humiditePublie = m_client.publish(m_topic_humidite, m_humiditeString);
  this->m_pressionPublie = m_client.publish(m_topic_pression, m_pressionString);

  if (m_temperaturePublie && m_humiditePublie && m_pressionPublie)
  {
    Serial.println("");
    Serial.println("Les données du BME280 on été envoyés!");
    m_temperaturePublie = false;
    m_humiditePublie = false;
    m_pressionPublie = false;
  }
}
void StationMeteoWifi::demarrerReseau()
{
  Serial.print("Connecting to ");
  Serial.println("SSID : " + String(this->m_SSIDPortail));
  Serial.println("PASSWORD : " + String(this->m_motPasseAPPortail));
  WiFi.begin(this->m_SSIDPortail, this->m_motPasseAPPortail);
  Serial.println(this->m_SSIDPortail);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to " + String(this->m_SSIDPortail));
}
void StationMeteoWifi::connexionMQTT() // Fonction pour se connecter au serveur MQTT
{
  while (!m_client.connected())
  {
    Serial.print("\nConnecting to ");
    Serial.println(this->m_broker);
    if (m_client.connect("1", this->m_brokerUser, this->m_brokerPass))
    {
      Serial.print("\nConnected to ");
      Serial.println(this->m_broker);
    }
    else
    {
      Serial.println("\nTrying to connect again");
    }
  }
};