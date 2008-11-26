=========
TP de PLC
=========

---------------------------------------------------
Prolog (programmation déclarative), Contrainte (RO)
---------------------------------------------------

:Auteur: Geoffroy Carrier
:Date: 2008-2009
:Contexte: L3 MIAGE UFR-IMAG

.. sectnum::
.. contents:: Index

TD 1
~~~~

plusun
======

``plusun/2: plusun(X,Y)`` ssi Y=X+1, X et Y étant les chiffres symboliques : ``un``, ``deux``, etc., ``neuf``. ``plusun`` est le nom du prédicat, ``2`` son arité (nombre de paramètres) ; les variables commencent par une majuscule, les constantes par une minuscule.

::

        plusun

TP de Prolog, prise en main
~~~~~~~~~~~~~~~~~~~~~~~~~~~

À rendre pour le 18 septembre.

Base de faits
=============

::

        % On utilise seulement le masculin pour ignorer le probleme de genre.
        
        % SPECIFICATION (S) : parent(X,Y) ssi X est le pere de Y.
        % REALISATION (R) : fournie.
        % JEUX D'ESSAIS (T) : inadapté.
        parent(agnes,clement).
        parent(agnes,gabrielle).
        parent(clement,jean).
        parent(gabrielle,pierre).
        parent(gabrielle,louise).
        parent(pierre,olive).
        parent(pierre,marie).

        % S : grandparent(X,Y) ssi X est le grand-pere de Y (i.e. le pere du pere).
        % R : Doit exister T, le fils de X et le pere de Y.
        % T : Test 1.
        grandparent(X,Y) :- parent(X,T), parent(T,Y).

        % S : frere(X,Y) ssi X est le frere de Y (i.e. ils ont un pere commun).
        % R : X et Y sont differents, et ont pour meme pere T.
        % T : Test 2.
        frere(X,Y) :- dif(X,Y), parent(T,X), parent(T,Y).

        % S : cousin(X,Y) ssi X est le cousin de Y (i.e. ils ont un pere different ayant un pere commun).
        % R : X et Y ont pour pere respectif T et U, qui sont freres.
        % T: Test 3.
        cousin(X,Y) :- parent(T,X), parent(U,Y), frere(T,U).

        % S : ancetre(X,Y) ssi X est un ancetre de Y (i.e. le pere du pere [...] de son pere).
        % R : Par recurrence, X est l'ancetre de Y s'il est son pere, ou s'il est l'ancetre d'un de ses peres.
        % T : Tests 4 et 5.
        ancetre(X,Y) :- parent(X,Y).
        ancetre(X,Y) :- parent(X,T), ancetre(T,Y).

        % S : mystere1(X,Y) ssi X et Y sont cousins éloignés (i.e. ancetre commun, meme degre de filiation a cet ancetre).
        % R : Par recurrence, X et Y sont cousins éloignés s'ils sont cousins directs, ou si leurs ancêtres sont cousins directs.
        % T : Test 6.
        mystere1(X,Y) :- dif(X,Y), parent(Z,X), parent(Z,Y).
        mystere1(X,Y) :- parent(Z,X), parent(W,Y), mystere1(Z,W).

        % S,R : voir mystere1/2.
        % T : Test 7.
        mystere2(X,Y) :- mystere2(Z,W), parent(Z,X), parent(W,Y).
        mystere2(X,Y) :- dif(X,Y), parent(Z,X), parent(Z,Y).


Arbre généalogique
==================

::

           agnes
           /   \
        clement gabrielle
         /        /  \
      jean    pierre louise
                /  \
            olive marie

Traces de requêtes
==================

Test 1
------

'ensemble des grands-parents et leurs petits-enfants. Le résultat obtenu est celui attendu à la lecture de l'arbre généalogique. ::

        ?- grandparent(X,Y).
        X = agnes,
        Y = jean ;
        X = agnes,
        Y = pierre ;
        X = agnes,
        Y = louise ;
        X = gabrielle,
        Y = olive ;
        X = gabrielle,
        Y = marie ;
        fail.

Test 2
------

L'ensemble des frères et sœurs. Comme attendu. ::

        ?- frere(X,Y).
        X = clement,
        Y = gabrielle ;
        X = gabrielle,
        Y = clement ;
        X = pierre,
        Y = louise ;
        X = louise,
        Y = pierre ;
        X = olive,
        Y = marie ;
        X = marie,
        Y = olive ;
        fail.

Test 3
------

L'ensemble des cousins et cousines. Comme attendu. ::

        ?- cousin(X,Y).
        X = jean,
        Y = pierre ;
        X = jean,
        Y = louise ;
        X = pierre,
        Y = jean ;
        X = louise,
        Y = jean ;
        fail.

Test 4
------

L'ensemble des descendants de ``agnes``. Comme attendu. ::

        ?- ancetre(agnes,U).
        U = clement ;
        U = gabrielle ;
        U = jean ;
        U = pierre ;
        U = louise ;
        U = olive ;
        U = marie ;
        fail.

Test 5
------

L'ensemble des ancètres de ``olive``. Comme attendu. ::

        ?- ancetre(U,olive).
        U = pierre ;
        U = agnes ;
        U = gabrielle ;
        fail.

Test 6
------

L'ensemble des cousins éloignés. Comme attendu, puisque des contraintes suffisantes sont introduites à chaque appel récursif. ::

        ?- mystere1(X,Y).
        X = clement,
        Y = gabrielle ;
        X = gabrielle,
        Y = clement ;
        X = pierre,
        Y = louise ;
        X = louise,
        Y = pierre ;
        X = olive,
        Y = marie ;
        X = marie,
        Y = olive ;
        X = jean,
        Y = pierre ;
        X = jean,
        Y = louise ;
        X = pierre,
        Y = jean ;
        X = louise,
        Y = jean ;
        fail.

Test 7
------

L'ensemble des cousins éloignés. Échoue comme attendu. La résolution de ``mystere2(X,Y)`` entraîne d'abord la recherche d'un couple (``W``, ``Z``) vérifiant ``mystere2(W,Z)``, dont la résolution entraîne d'abord ..., ce qui boucle avant d'apporter des contraintes supplémentaires. ::

        ?- mystere2(X,Y).
        ERROR: Out of local stack
                Exception: (220,266) mystere2(_L4185060, _L4185061) ? 


L'arbre d'exécution tel que dans le cours est : ::

        m(X,Y)
        m(Z,W),parent(Z,X),parent(Z,Y)
        m(Z2,W2),parent(T,Z2),parent(T,W2),parent(Z,X),parent(Z,Y)
        m(Z3,W3),parent(T2,Z3),etc.
