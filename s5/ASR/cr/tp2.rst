===========
TP 2 Réseau
===========


Le protocole **ARP**
=====================

Syntaxe des paquets **ARP**
----------------------------

Tout d'abord, nous avons vidé le cache **ARP** via la commande : ::

  arp -d -a

Nous avons ensuite lancé un ping vers la station 192.168.0.1 et capturé le résultat
à l'aide de tcpdump et analysé visuellement le résultat dans *Wireshark* (ethereal),
dont la capture d'ecran et donnée en annexe `Structure d'une requète ARP`_.

Identification de la trame :
::::::::::::::::::::::::::::

Comme on peut le constater sur la capture d'écran, le champ *Type* de la 
trame ethernet (surligné en bleu) contient la valeur 0x0806 et permet d'identifier 
le paquet comme étant une requête **ARP**.

Place de la requète ARP dans le paquet :
::::::::::::::::::::::::::::::::::::::::

La requète **ARP** se situe dans le champ *data* du paquet.

Format de la trame **ARP**
::::::::::::::::::::::::::

Toujours d'après notre capture d'écran de *Wireshark*, nous pouvons determiner la structure
du paquet **ARP** de cette manière : ::

        0        16        32      40      48         64         112        144       192       224
        | HT (16) | PT (16) | HS(8) | PS(8) | OpC (16) | SMA (48) | SIA (32) | TMA(48) | TIA(32) |

Les champs étant :

+ HT : hardware type,
+ PT: Protocole type,
+ HS : Hardware Size,
+ PS : Protocole Size,
+ OpC : Opcode.
+ SMA : Sender Mac Address,
+ SIA : Sender IP Address,
+ TMA : Target MAC Address,
+ TIA : Target IP Address,

Les différents champs sont visible dans la capture d'écran donnée en annexe `Structure d'une requète ARP`_.

Taille :
::::::::

Les trames ont un marqueur de début et de fin, ce qui permet de les isoler à la réception.
La couche **Ethernet** ignore la taille des paquets qu'elle transporte ; la gestion est déléguée au support des 
couches supérieures (taille fixe dans le cas d'ARP).
A l'émission, le support des couches supérieures s'occupe de la découpe de ses paquets selon les besoins (notament IPv4/6).

Transmission entre le paquet **ARP** et la couche **Ethernet**
===============================================================

Toute la zone data : paquet + trailer (série de zéros permettant de compléter la trame) est transmise.
En considérant qu'un "bourrage" est un paquet ne tenant pas dans la zone *data* d'une trame, la couche **Ethernet** n'ayant aucune connaissance de la nature des données transportées en dehors de leur type qui indique à quel support de couche supérieure transmettre les données à la réception, elle ne se soucie pas des problématiques de bourrage qui sont déléguées à ce support.
Dans le cas d'ARP il n'y a pas e gestion du bourrage et les trames **Ethernet** doivent être d'une longueur suffisante pour en assurer le transport (trames de 42 o en excluant le préambule).


Algorithme du protocole **ARP**
===============================

Après avoir effectuer les manipulations dictées par l'énoncé, nous avons complété l'algorithme de la 
manière suivante : ::

  tantque vrai faire
    attendre(événement)
       si événement est (requête interne de IP vers ARP) :
          si présent dans table ARP :
          sinon :
             envois requete ARP
          finsi.
       finsi.
       si événement est expiration du timer associé à une entrée
          Suppression de l'entrée dans la table ARP
       finsi.

       si événement est réception requête (ARP Request)
          si adresse MAC cible == adresse MAC locale :
             envois reponse ARP avec MAC locale.
             MAJ table ARP avec les infos de la source.
          finsi.
       finsi.
       si événement est réception réponse (ARP Reply) :
          si requete addressee à machine locale :
             Mise à jour de la table ARP.
          finsi.
       finsi
      ... (attention il y a d’autres évenements)
  fin tantque

Structure d'une requète ARP
===========================

.. figure:: arp1.png
        :width: 15cm



