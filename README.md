
Description du projet

Nous avons été mandatés pour créer une station météo nous donnant la température, l’humidité, la pression atmosphérique et l’altitude. Ses données devront être envoyé sur un serveur MQTT et ensuite être affiché sur Home Assistant avec des entités. De plus, nous avons décidé d’innover le concept en ajoutant une station d’affichage avec écran tactile qui permettra à l’utilisateur de configurer son produit de manière simple. L’utilisateur pourra voir les données reçues par la station émettrice ainsi que les prédictions de vent et de précipitation pour la journée courante.


Planification et attribution des tâches et description des étapes du projet


Pour la planification de ce projet, nous avons premièrement pris conscience entièrement des besoins du client pour ensuite commencer à élaborer un plan et à déterminer nos objectifs. Nous avons établi un calendrier et mener une évaluation de la difficulté des tâches à venir pour anticiper les problèmes éventuels possibles.

Nous avons décidé que Raphaël s’occuperais de la programmation de la station d’affichage et Marc-Antoine de la station émettrice. Nous avons décidé d’utiliser la technologie « esp-now » qui nous permet de faire communiquer plusieurs esp32 entre eux pour échanger les données de connexion au réseau. Ce qui permet d’éviter une configuration plus complexe passant par un client sur un navigateur web.

Taches			Raphael	Marc-Antoine	Total	
Documentation		3h	3h	6h	
Écran			35h	2h	47h	
Senseur/HomeAssistant			3h	20h	15h	
Dessin Circuit		5m	15m	20m	
Diagram de Classes		0m	30m	30m	
Vidéo YouTube		4h	0h	4h	
			45.083h	25.75h	70.833h	
						

Diagramme de classe
Diagramme station émettrice
 


Diagramme station d’affichage
 

Inventaire des pièces et couts en dollars canadien
Article	 	 	Quantité	Prix	Total	
ESP32	 	 	2	13.99	27.98	
Écran ili9488	 	 	1	17.99	17.99	
BME280	 	 	1	14.99	14.99	
Mini “BreadBoard”	1	4.99	4.99	
PLA	 	 	0.512m	3.22	3.22	
Bornier	 	 	17	0.30	5	
					73.18	


Estimation énergétique

La consommation est sur secteur et consomme dans le pire des cas est de +/- 0.23 watts


Schéma technique avec explications

Station émettrice

 

La station émettrice n’a besoin que de 4 pins, une pour le courant, une pour le ‘ground’ et puis finalement les deux autres (SCL et SDA) pour la transmettre les données

Station d’affichage

 
