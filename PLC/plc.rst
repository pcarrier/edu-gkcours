=============================
Cours d'introduction à la PLC
=============================

---------------------------------------------------
Prolog (programmation déclarative), Contrainte (RO)
---------------------------------------------------

:Auteur: Denis Bouhineau
:Date: 2008-2009
:Contexte: L3 MIAGE UFR-IMAG

.. sectnum::
.. contents:: Index

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

Webographie
-----------

- *P99, 99 problèmes en IA*
- *SWI-Prolog*
- *ioctl.org*
- *jscriptlog*

Syntaxe et objets Prolog
========================

::

        Terme ::= Variable | Atome | Entier | Flottant | Terme composé
        Terme composé ::= Atome "(" Terme { "," Terme } * ")"
        Variable : identificateur commencant par une majuscule ou "_"
        Atome : identificateur commencant par une minuscule

Exemple de terme composé : ::

        avant(l1,l2).

Remarque : ``+`` peut se noter de manière infixée, ``4+3`` ou postfixé, ``+(4,3)``. De même pour ``.`` : ``avant(l1,l2).`` est équivalent à ``.(avant(l1,l2))``

Termes particuliers : ::
        
        Pour les listes [] [n|n] [e|L]
        Corps ::= Corps ","  Corps
                | Corps ";"  Corps
                | Corps "->" Corps
                | Variable
                | Prédicat

Unification
===========

Substitution
------------

::

        sigma: {X1<-t1,X2<-t2,X3<-t3,..,Xn<-tn}

Chercher une unification entre ``f(S1,..,Sn)`` et ``f(T1,..,Tn)``.

On applique **4 règles** : ::

Séparation
----------

On remplace ``f(S1,..,Sn) = f(T1,..,Tn)`` en ``S1 = T1``, .., ``Sn = Tn``.

Suppression des identités
-------------------------

On élimine ``X = X``.

Ordre : les variables en 1er
----------------------------

On remplace les équations ``t = X`` par ``X = t``.

Élimination des variables
-------------------------

Si on a une équation ``X = u``, on remplace toutes les occurences de ``X`` par ``u`` : on remplace les équations ``s = t`` où X apparait par ``s{X<-u}=t{X<-u}``.
        

Moteur d'exécution Prolog
=========================

Principe
--------

- **En entrée :** une requête, un ensemble de règles (faits, clauses).
- **Algorithme de résolution**

  - Initialisation : ``G <- requête``, ``sigma <- {}``
  - Si G est "vrai" : **succès**
  - Sinon on choisit un prédicat A dans G
  - Si A est vrai alors on le supprime et on part à l'étape 2.
  - Si aucune clause dans l'ensemble de règles n'a une tête qui s'unifie avec A alors échec.
  - Sinon on choisit parmi les règles dont la tête s'unifie avec A, une règle ``H :- B`` grâce à la substitution SigmaAH
  - On remplace dans G le prédicat A par B et on applique la substitution ``SigmaAH``, ``Sigma <- SigmaAH x Sigma`` et on continue à l'étape 2.

Exemple
-------

::

        trie([]).
        trie([X]).
        trie([E|L]) :- trie(L), premierElement(X,L), E <= X.
        premierElement(E,[E|L]).

        recherche(X,[X|L]).
        recherche(X,[T|L]) :- recherche(X,L).

        concatene([],[],X).
        concatene(X,[A|Y],[A|L]) :- concatene(X,Y,L).
        concatene([A|X],[],[A|L]) :- concatene(X,[],L).
