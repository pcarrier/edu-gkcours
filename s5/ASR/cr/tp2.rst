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
à l'aide de tcpdump et analysé visuellement le résultat dans *Wireshark* (ethereal).
Comme on peut le constater sur le screenshot de  ci-dessous, le champ *Type* de la 
trame ethernet (surligné en bleu) contient la valeur 0x0806 et permet d'identifier 
le paquet comme étant une requête **ARP**.

La requète **ARP** se situe dans le champ *data* du paquet.

Format de la trame **ARP**
::::::::::::::::::::::::::

Toujours d'après notre capture d'écran de *Wireshark*, nous pouvons determiner la structure
de la trame **ARP** de cette manière : ::

|Hardware Type(2)|Protocole Type(2)|Hardware size(1)|Protocole size(1)|Opcode (2)|Addr Mac src(6)|Addr IP src (4)|Addr MAC dest(6)|Addr IP dest(4)|


