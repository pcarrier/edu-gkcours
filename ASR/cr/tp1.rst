===========
TP 1 Réseau
===========

On choisit le réseau de classe C 192.168.42.0/24.

ping
----

La machine sur laquelle est exécuté ``ping`` envoie une suite de paquets ICMP à sa cible.
Elle utilise des requêtes ICMP 8, et des numéros de séquence croissants en partant de 0.

La machine cible envoie des paquets ICMP de réponse à la machine source.
Elle utilise des réponses ICMP 8, et conserve le numéro de séquence.

La machine source affiche à chaque réponse reçue la taille du paquet, sa source, son numéro de séquence et le délai entre émission et réception.
À la réception d'un signal de terminaison, elle affiche des statistiques : nombre de requêtes émises, nombre de réponses reçues, pourcentage de perte, et des statistiques sur les délais de réception de la réponse.

Table ARP
---------

La table ARP contient l'ensemble des associations entre adresse matérielle (MAC), adresse IPv4, nom d'hôte et interface.

Les paquets ARP n'apparaissent pas avant chaque paquet ICMP request car les associations sont mises en cache dans la table et conservés avant ``timeout`` ou changement d'état.


CSMA/CD
-------

- 2 machines, 0 collisions/s.
- 4 machines, environ 40 collisions/s, 4 erreurs/s, quelle que soit la taille des paquets.

Performances réseau
-------------------

- Paquets de 1 octet : 118 kbit/s, paquets de 60 o dont 1 o de données ;
-   10 o : 1176 kbit/s, 60 o dont 10 o ;
-   20 o : 2299 kbit/s, 62 o dont 20 o ;
-  100 o : 5988 kbit/s, 142 o dont 100 o ;
- 1000 o : 9372 kbit/s, 1042 o dont 1000 o ;
- 1450 o : 9558 kbit/s, 1492 o dont 1450 o ;
- 2000 o : 9407 kbit/s, (1514+562) dont (1480+520) o ;
- 3000 o : 9419 kbit/s, (1514+1514+82) dont (1480+1480+40).

Les débits observés dont dues à l'overhead de 42 octets par trame.

Explication par trames
----------------------

Chaque paquet UDP passe sur un certain nombre de trames. Chaque trame contient au maximum un paquet IP d'une longueur totale de 1500 octets, dont 1480 octets de données.


