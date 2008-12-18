================================
Modélisation et interopérabilité
================================

---------------------------------------------------
SGML ? XML XML XML... XML XML XML... Protobuffers !
---------------------------------------------------

:Auteur: Geoffroy Carrier
:Date: 2008-2009
:Contexte: L3 MIAGE UFR-IMAG

TP1 : XML-DTD
~~~~~~~~~~~~~

Document XML
============

1. Le document est malformé : le XML est sensible à la casse pour les balises et arguments (erreur <lecture></Lecture>) et représente des arbres, le document doit donc avoir un nœud racine. Possèdent des sous-éléments ``<week/>`` et ``<holidays/>``.

2. Le doucment est bien formé ; ``<aa/>`` et ``<bb/>[1]`` ont 3 fils.

Information avec structuration simple
=====================================

DTD
---

::

        <!ELEMENT ville #PCDATA>
        <!ELEMENT date #PCDATA>
        <!ELEMENT temperatureMin #PCDATA>
        <!ELEMENT temperatureMax #PCDATA>
        <!ELEMENT meteo (ville,date,temperatureMin,temperatureMax)>
        <!--
        noeud+ 1+ fois
        noeud? 0/1 fois
        noeud* 0+ fois
        a,b a puis b
        a|b a ou b
        Parenthesage
        -->

Exemple
-------

::
        
        <?xml version="1.0"?>
        <!DOCTYPE meteo SYSTEM "meteo.dtd">
        <meteo>
                <ville>Grenoble</ville>
                <date>2008-09-10</date>
                <temperatureMin>12</temperatureMin>
                <temperatureMax>24</temperatureMax>
        </meteo>

Information avec hiérarchie de contenu
======================================

Trivial... En gros ::

        <!ELEMENT ville (nom,pays)>

Utilisation des cardinalités
============================

::

        <!ELEMENT polyedre (face*)>
        <!ELEMENT face (sommet*)>
        <!ELEMENT sommet (x,y,z)>
        <!ELEMENT x #PCDATA>
        <!ELEMENT y #PCDATA>
        <!ELEMENT z #PCDATA>

Utilisation des références
==========================

::

        <!ATTLIST note
                matiere IDREF   #IMPLIED>
        <!ATTLIST matiere
                id      ID      #REQUIRED>
