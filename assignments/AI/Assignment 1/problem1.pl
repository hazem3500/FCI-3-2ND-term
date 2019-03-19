%first line
connected(new_elmarg,elmarg).
connected(elmarg,ezbet_elnakhl).
connected(ezbet_elnakhl,ain_shams).
connected(ain_shams,elmatareyya).
connected(elmatareyya,helmeyet_elzaitoun).
connected(helmeyet_elzaitoun,hadayeq_elzaitoun).
connected(hadayeq_elzaitoun,saray_elqobba).
connected(saray_elqobba,hammamat_elqobba).
connected(hammamat_elqobba,kobri_elqobba).
connected(kobri_elqobba,manshiet_elsadr).
connected(manshiet_elsadr,eldemerdash).
connected(eldemerdash,ghamra).
connected(ghamra,alshohadaa).
connected(alshohadaa,urabi).
connected(urabi,nasser).
connected(nasser,sadat).
connected(sadat,saad_zaghloul).
connected(saad_zaghloul, alsayyeda_zeinab).
connected(alsayyeda_zeinab,elmalek_elsaleh).
connected(elmalek_elsaleh,margirgis).
connected(margirgis,elzahraa).
connected(elzahraa,dar_elsalam).
connected(dar_elsalam,hadayeq_elmaadi).
connected(hadayeq_elmaadi,maadi).
connected(maadi,thakanat_elmaadi).
connected(thakanat_elmaadi,tora_elbalad).
connected(tora_elbalad,kozzika).
connected(kozzika,tora_elasmant).
connected(tora_elasmant,elmaasara).
connected(elmaasara,hadayeq_helwan).
connected(hadayeq_helwan,wadi_hof).
connected(wadi_hof,helwan_university).
connected(helwan_university,ain_helwan).
connected(ain_helwan,helwan).
%second line
connected(shobra_elkheima,koliet_elzeraa).
connected(koliet_elzeraa,mezallat).
connected(mezallat,khalafawy).
connected(khalafawy,sainte_teresa).
connected(sainte_teresa,road_elfarag).
connected(road_elfarag,massara).
connected(massara,alshohadaa).
connected(alshohadaa,ataba).
connected(ataba,naguib).
connected(naguib,sadat).
connected(sadat,opera).
connected(opera,dokki).
connected(dokki,bohooth).
connected(bohooth,cairo_university).
connected(cairo_university,faisal).
connected(faisal,giza).
connected(giza,omm_elmisryeen).
connected(omm_elmisryeen,sakiat_mekki).
connected(sakiat_mekki,elmounib).

% %helpers

checkConnect(FIRST_STATION, SECOND_STATION):-
   connected(FIRST_STATION, SECOND_STATION);
   connected(SECOND_STATION, FIRST_STATION).

listSize([], 0).

listSize([_|T], R):-
    listSize(T, R1),
        R is R1 + 1.

append([], X, X).

append([H|T], X, [H|L2]):-
   append(T, X, L2).


numOfOccurrences([], _, 0).

numOfOccurrences([[_, N]|T], N, OCCURRENCE):- 
   numOfOccurrences(T,N,Z),
   OCCURRENCE is Z + 1.

numOfOccurrences([[N, _]|T], N, OCCURRENCE):- 
   numOfOccurrences(T,N,Z),
   OCCURRENCE is Z + 1.

numOfOccurrences([_|T],N,Z):-
   numOfOccurrences(T,N,Z).


getAllStations(STATIONS):-
   path(new_elmarg, helwan, any, FIRST_LINE),
   path(shobra_elkheima, elmounib, any, SECOND_LINE),
   append(FIRST_LINE, SECOND_LINE, STATIONS).


% %task1
getPath(SOURCE, DESTINATION, _, [[SOURCE, DESTINATION]]):-
   checkConnect(SOURCE, DESTINATION).

getPath(SOURCE, DESTINATION, any, [[SOURCE, STATION_IN_BETWEEN] | REST_OF_PATH]):-
   connected(SOURCE, STATION_IN_BETWEEN),
   path(STATION_IN_BETWEEN, DESTINATION, any, REST_OF_PATH).


getPath(SOURCE, DESTINATION, N, [[SOURCE, STATION_IN_BETWEEN] | REST_OF_PATH]):-
   N \= any,
   connected(SOURCE, STATION_IN_BETWEEN),
   N1 is N - 1,
   N1 >= 0,
   path(STATION_IN_BETWEEN, DESTINATION, N1, REST_OF_PATH).

path(SOURCE, DESTINATION, N, PATH):-
   getPath(DESTINATION, SOURCE, N, PATH); 
   getPath(SOURCE, DESTINATION, N, PATH).

% %---------------------------------------------------------------------

% %task2
nstations(STATION, L):-
   getAllStations(STATIONS),
   numOfOccurrences(STATIONS, STATION, L).

% %---------------------------------------------------------------------

% %task3

cost(SOURCE, DESTINATION, N):-
   path(SOURCE, DESTINATION, any, PATH),
   listSize(PATH, NUM_OF_STATIONS),
   getPrice(NUM_OF_STATIONS ,N).

getPrice(NUM_OF_STATIONS, PRICE):-
   (NUM_OF_STATIONS < 8, PRICE = '3 EGP');   
   (NUM_OF_STATIONS < 16, PRICE = '5 EGP');   
   PRICE = '7 EGP'.


