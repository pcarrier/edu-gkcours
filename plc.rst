=============================
Cours d'introduction à la PLC
=============================

---------------------------------------------------
Prolog (programmation déclarative), Contrainte (RO)
---------------------------------------------------

:Auteur: Denis Bouhineau
:Date: 2008-2009
:Contexte: L3 MIAGE UFR-IMAG

Principe
========

- Déclarer des faits
- Énoncer des règles de raisonnement (programmation)
- Poser des questions (exécution)


**Exemple :** ::

   avant(l2,l3). ; l2 est avant l3
   deuxansavant(X,Y) :- avant(X,Tmp),avant(Tmp,Y).
   ? deuxansavant(l2,m1).
   -> yes
   ? deuxansavant(l2,X).
   -> {X=m1}
   ? deuxansavant(X,m1).
   -> {X=l2}
   ? deuxansavant(X,Y).
   -> {X=l2,Y=m1}


Histoire
========

En 1972, après entre autres Algol et le C, apparition de Prolog, prévu pour l'analyse syntaxique, la construction d'arbres et la logique. Structures de données construites dans le langage.

Motivation pédagogique
======================

- Traité

  - Simple (syntaxe)
  - Haut niveau
  - Algorithmique

    - Récursivité
    - Structures de données
    - Base de données
    - Modélisation
    - Parallélisme
    - Graphe
    - Logique

- Pas traité dans le cours

  - IHM
  - Gros programme

- Point difficile !

  - Apprentissage difficile

Organisation du cours
=====================

Plan
----

À chaque fois, un TP à rendre.

1. B.A.BA Prolog (1/3, 1 TP à rendre)
2. Algorithmique (1/3, 1 TP à rendre)
3. Contraintes

Bibliographie
-------------

- *Cours de Prolog en TurboProlog* par J.P. Delahaye
- *Prolog : the standard* par P. Deransart
- *P99, 99 problèmes en IA* sur le Web
- *SWI-Prolog*
- *ioctl.org*
- *jscriptlog*
