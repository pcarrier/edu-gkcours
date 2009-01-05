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

- Paquets de 1 octet : 118 kbit/s, paquets IP de 60 o dont 1 o de données ;
-   10 o : 1176 kbit/s, 60 o dont 10 o ;
-   20 o : 2299 kbit/s, 62 o dont 20 o ;
-  100 o : 5988 kbit/s, 142 o dont 100 o ;
- 1000 o : 9372 kbit/s, 1042 o dont 1000 o ;
- 1450 o : 9558 kbit/s, 1492 o dont 1450 o ;
- 2000 o : 9407 kbit/s, (1514+562) dont (1480+520) o ;
- 3000 o : 9419 kbit/s, (1514+1514+82) dont (1480+1480+40).

Les débits observés dont dues à l'overhead de 42 octets par paquet au niveau d'UDP+IP, puis 12 octets au niveau d'Ethernet. On négligera le silence inter-trame.

On observe la corrélation prévisible entre le ratio données utiles transmises/données transmises et le débit obtenu.

Plusieurs trafics
-----------------

Les débits moyens sont similaires entre les 2 échanges et totalisent environ 7,3MBit/s avec un hub ; le ``ping`` explose à environ 16ms. L'équité est due à la gestion des collisions d'Ethernet.

Avec un switch, dans le cas de deux échanges entre quatre machines où chacune d'elle reçoit ou émet un flux, les débits respectifs correspondent aux résultats obtenus dans la configuration à deux postes. Les délais de ``ping`` sont aussi bas.

Avec un switch, dans le cas de trois machines émettant des flux vers une seule machine, le débit total est équitablement partagé entre les flux et approche les résultats obtenus dans la configuration à deux postes. Les délais de ``ping`` explosent.

Les délais de ``ping`` explosent dans des contextes aux nombreuses collisions Ethernet.

Exercice de synthèse
--------------------

Si plusieurs étudiants utilisent la même adresse IP, chaque nœud souhaitant joindre cette IP effectuera une requête ARP. Le premier à répondre verra son adresse MAC stockée dans la table ARP du nœud et sera donc joint par celui-ci jusqu'à expiration de l'entrée.