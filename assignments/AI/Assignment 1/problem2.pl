word(zombifies, [z, o, m, b, i, f, i, e, s]). 
word(akecabele, [a, k, e, c, a, b, e, l, e]). 
word(brickwork, [b, r, i, c, k, w, o, r, k]). 
word(backcheck, [b, a, c, k, c, h, e, c, k]). 
word(acmrremad, [a, c, m, r, r, e, m, a, d]). 
word(nhgwpfabz, [n, h, g, w, p, f, a, b, z]). 
word(jellybean, [j, e, l, l, y, b, e, a, n]). 
word(earreoded, [e, a, r, r, e, o, d, e, d]). 

puzzle(V1, V2, V3, V4 ,H1 ,H2 ,H3, H4):-
    word(V1, [_, V1H1, _, V1H2, _, V1H3, _, V1H4, _]),
    word(V2, [_, V2H1, _, V2H2, _, V2H3, _, V2H4, _]),
    word(V3, [_, V3H1, _, V3H2, _, V3H3, _, V3H4, _]),
    word(V4, [_, V4H1, _, V4H2, _, V4H3, _, V4H4, _]),
    word(H1, [_, V1H1, _, V2H1, _, V3H1, _, V4H1, _]),
    word(H2, [_, V1H2, _, V2H2, _, V3H2, _, V4H2, _]),
    word(H3, [_, V1H3, _, V2H3, _, V3H3, _, V4H3, _]),
    word(H4, [_, V1H4, _, V2H4, _, V3H4, _, V4H4, _]).
