parent(pan, bob). 
parent(tom, bob). 
parent(lol, bob). 
parent(tom, iiz). 
parent(bob, pan). 
parent(bob,pat). 
parent(pat, im). 
parent('Hamada', 'hamda'). 

child(X, Y):-
    parent(Y, X).

grandParent(X, Y):-
    parent(X, Z),
        parent(Z, Y).

predecessor(X, Y):-
    parent(X, Y).

predecessor(X, Y):-
    parent(X, Z),
        predecessor(Z, Y).

hasChild(X):-
    parent(X, _).