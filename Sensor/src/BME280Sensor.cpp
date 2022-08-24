// *********************************************************************************************************************************************************************
// Nous avions créer cette classe pour séparer le bmeSensor de la gestion du wifi et de l'envois de données mais nous arrivions pas a faire le tout fonctionner ensemble.
// Nous avons donc instancié un bmeSensor directement dans la classe StationMeteoWifi pour nous faciliter la tâche et par manque de temps.





// #include <BME280Sensor.h>
// BME280Sensor::BME280Sensor(char *p_payload_temperature, char *p_payload_humidite, char *p_payload_pression)
// {
//     this->payload_temperature = p_payload_temperature;
//     this->payload_humidite = p_payload_humidite;
//     this->payload_pression = p_payload_pression;
//     this->m_bme.begin(0x76);

//     if (!this->m_status)
//     {
//         Serial.println("Could not find a valid BME280 sensor, check wiring!");
//         while (1)
//             ;
//     }
// };
// void BME280Sensor::loop()
// {
//     if (millis() > this->tempPresent + tempDuneBoucle)
//     {
//         this->tempPresent = millis();
//         this->enregistrerDonneesBME();
//     }
// };
// void BME280Sensor::enregistrerDonneesBME()
// {
//     this->temperatureString = String(this->m_bme.readTemperature());
//     this->payload_temperature = new char[temperatureString.length() + 1];

    

//     this->humiditeString = String(this->m_bme.readHumidity());
//     this->payload_humidite = new char[humiditeString.length() + 1];

//     this->pressionString = String(this->m_bme.readPressure());
//     this->payload_pression = new char[pressionString.length() + 1];

//     this->altitudeString = String(this->m_bme.readAltitude(SEALEVELPRESSURE_HPA));
//     this->payload_altitude = new char[altitudeString.length() + 1];

//     this->temperatureString.toCharArray(this->payload_temperature, temperatureString.length() + 1);
//     this->humiditeString.toCharArray(this->payload_humidite, humiditeString.length() + 1);
//     this->pressionString.toCharArray(this->payload_pression, pressionString.length() + 1);
//     this->altitudeString.toCharArray(this->payload_altitude, altitudeString.length() + 1);
// };