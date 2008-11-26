=============================
Architecture, Système, Réseau
=============================

------------------------------
Notes du cours Denis Bouhineau
------------------------------

:Auteur: Geoffroy Carrier
:Date: 2008-2009
:Contexte: L3 MIAGE UFR-IMAG

Introduction
~~~~~~~~~~~~

Intérêt pédagogique
===================

- Culture du matériel
- Système / Réseau
- Compilation
- Logique
- UML

Plan
====

- Introduction à la logique
- Circuit combinatoire
- Circuit séquentiel
- Automate d'interprétation du langage machine
- Automate de contrôle
- Au-dela

Bibliographie
=============

- *Architecture logicielle et matérielle* par Amblard, Fernandez et al. (Dunod)
- *Architecture des ordinateurs* par Andrew S. Tanenbaum
- *Architecture des ordinateurs* par John L. Hennessy et David Patterson
- *Computer Systems: A Programmer's Perspective* par Randal E. Bryant et David R. O'Hallaron

Algèbre de Boole : logiciel classique du premier ordre
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

L'espace B = { 0,1}
====================

On construit B^n= { (0,0,..,0), (0,..,0,1),..,(1,1,..,1) } à 2^n éléments.

Représentation
--------------

.. sidebar:: Table des éléments de B^3

  == == ==
  b2 b1 b0
  == == ==
  0  0  0
  0  0  1
  0  1  0
  0  1  1
  1  0  0
  1  0  1
  1  1  0
  1  1  1
  == == ==

- n-uplets
- Table
- Tableau à deux dimensions (dont le tableau de Karnaugh)
- Hypercube
- Arbre binaire

Représentation de l'information
-------------------------------

- Numérique

  - Entiers naturels : (b_n,..,b_0) = Sigma_{i=0}^n b_i 2^i
  - Entiers relatifs : S+V, C1, C2, Ex à réviser (on peut voir `le cours de Nantes`_)
  - Nombres rationnels

- Non-numérique, comme caractère ASCII (voir `ASCII(7)`_)
  
.. _ASCII(7): http://www.freebsd.org/cgi/man.cgi?query=ascii&manpath=FreeBSD+7.0-RELEASE)
.. _le cours de Nantes: http://www.sciences.univ-nantes.fr/info/perso/permanents/bouhineau/Enseignement/Architecture/CoursRepresentationInformations.htm
