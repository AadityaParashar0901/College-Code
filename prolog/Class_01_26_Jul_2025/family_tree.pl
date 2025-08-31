parent(tom, bob).
parent(pam, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(liz, fiz).
parent(liz, sil).
male(tom).
male(bob).
male(pat).
male(sil).
female(pam).
female(liz).
female(ann).
female(fiz).

father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).

sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), sibling(X, Y).
sister(X, Y) :- female(X), sibling(X, Y).

grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

cousin(X, Y) :- parent(A, X), parent(B, Y), sibling(A, B), X \= Y.

