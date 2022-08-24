# Station météo

# Images

<p align="center">
<img src="./img/homeGarden5000.jpg"
     alt="Markdown Monster icon"/>
</p>

<p align="center">
<img src="./img/info.jpg"
     alt="Markdown Monster icon"/>
</p>

<p align="center">
<img src="./img/wifiManager.png"
     alt="Markdown Monster icon"/>
 </p>

<p align="center">
<img src="./img/GUI.png"
     alt="Markdown Monster icon"/>
</p>

# Description du projet

Avec un senseur BME280, on récupère la température, l'humidité, la pression atmosphérique, et on envoie les informations vers Home Assistant un logiciel de domotique avec MQTT(PUB/SUB).
Le 2eme esp32 avec l’écran tactile ILI9488 sert comme wifi manager et affiche les informations de la bme280, et affiche aussi la météo locale a l’aide d’un API.

# Planification et attribution des tâches et description des étapes du projet

Pour la planification de ce projet, nous avons premièrement pris conscience entièrement des besoins du client pour ensuite commencer à élaborer un plan et à déterminer nos objectifs. Nous avons établi un calendrier et mener une évaluation de la difficulté des tâches à venir pour anticiper les problèmes éventuels possibles.

Nous avons décidé que Raphaël s’occuperais de la programmation de la station d’affichage et Marc-Antoine de la station émettrice. Nous avons décidé d’utiliser la technologie « esp-now » qui nous permet de faire communiquer plusieurs esp32 entre eux pour échanger les données de connexion au réseau. Ce qui permet d’éviter une configuration plus complexe passant par un client sur un navigateur web.


# Schéma technique

<img src="./img/ESP32BME.png"
     alt="ESP32BME"
     style="float: left; margin-right: 10px;" />

<img src="./img/ESP32ILI9488.png"
     alt="ESP32ILI9488"
     style="margin-right: 10px;" />

<br>

# Diagram de classes
<p align="center">
<img src="./img/diagramEmetteur.png"
     alt="diagramEmetteur"/>
</p>

<p align="center">
<img src="./img/diagramEcran.png"
     alt="diagramEcran"/>
</p>



# DEMO
https://www.youtube.com/watch?v=gJ58MvmqERE
