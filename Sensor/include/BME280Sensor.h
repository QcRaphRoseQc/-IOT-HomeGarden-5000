
// *********************************************************************************************************************************************************************
// Nous avions créer cette classe pour séparer le bmeSensor de la gestion du wifi et de l'envois de données mais nous arrivions pas a faire le tout fonctionner ensemble.
// Nous avons donc instancié un bmeSensor directement dans la classe StationMeteoWifi pour nous faciliter la tâche et par manque de temps.





// #include <Adafruit_BME280.h>
// #define SEALEVELPRESSURE_HPA (1013.25)
// class BME280Sensor
// {
// private:
//     Adafruit_BME280 m_bme; // I2C
//     bool m_status;

    
//     String temperatureString;
//     char *payload_temperature;

//     String humiditeString;
//     char *payload_humidite;

//     String pressionString;
//     char *payload_pression;

//     String altitudeString;
//     char *payload_altitude;

    
//     int tempDuneBoucle = 1000; // en milliseconde
//     unsigned long tempPresent = 0;

// public:
//     BME280Sensor(char *p_payload_temperature, char *p_payload_humidite, char *p_payload_pression);
//     void loop();
//     void enregistrerDonneesBME();
// };