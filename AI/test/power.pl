power(X, 1, X):-!.

power(X, N, P):-
    N1 is N - 1,
    power(X, N1, P1),
    P is X * P1.