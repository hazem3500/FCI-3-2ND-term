contains([X|_], X).

contains([_|T], X):-
    contains(T, X).


remove(X, [X|T], T).

remove(X, [H|T], [H| T1]):-
    remove(X, T, T1).


beforeLast([H|[_]], H).

beforeLast([_|T], X):-
    beforeLast(T, X).


append([], X, X).

append([H|T], X, [H|L2]):-
    append(T, X, L2).


addToList(_, [], []).

addToList(X, [H|T], [H1|T1]):-
    H1 is H + X,
    addToList(X, T, T1).


adjacent(X, Y, [X,Y|_]).

adjacent(X, Y, [_|T]):-
    adjacent(X, Y, T).


listSize([], 0).

listSize([_|T], R):-
    listSize(T, R1),
        R is R1 + 1.


listSum([], 0).

listSum([H|T], R):-
    listSum(T, R1),
        R is R1 + H.


nthElement([H|_], 0, H).

nthElement([_|T], N, R):-
    N1 is N - 1,
    nthElement(T, N1, R).

