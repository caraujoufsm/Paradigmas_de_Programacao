%1 - Defina um predicado somaQuad(X,Y,Q) que seja verdadeiro se Q for a soma dos quadrados de X e Y. 
prod(X,Y,Z) :- Z is X*Y.
somaQuad(X,Y,Q) :- prod(X,X,Z) , prod(Y,Y,W) , Q is Z + W.

%2 - Defina um predicado zeroInit(L) que é verdadeiro se L for uma lista que inicia com o número 0 (zero).
zeroInit(L) :- L=[H|_] , H=:=0.

%3 - Defina um predicado hasEqHeads(L1,L2) que seja verdadeiro se as listas L1 e L2 possuírem o mesmo primeiro elemento. 
hasEqHeads(L1,L2) :- L1=[H|_] , L2=[C|_] , H = C.

%4 - Defina um predicado has5(L) que seja verdadeiro se L for uma lista de 5 elementos. Lembre de como funciona a unificação em Prolog e resolva este exercício sem usar o predicado pré-definido length.
contador([],0).
contador([_|T],E) :-
	contador(T,C),
	E is C + 1.

has5(L) :- contador(L,E), E = 5.

%5 - Defina um predicado hasN(L,N) que seja verdadeiro se L for uma lista de N elementos. Agora você pode usar um predicado pré-definido.
hasN(L,N) :- length(L,N).

%6 - Defina um predicado isBin(L) que seja verdadeiro se L for uma lista contendo somente elementos 0 e 1. Use recursão. 
isBin([0]).
isBin([1]).
isBin(L) :- L=[H|T] , H =< 1, H >= 0 ,  isBin(T).

%7 - Defina um predicado mesmaPosicao(A,L1,L2) para verificar se um elemento A está na mesma posição nas listas L1 e L2. Assuma que L1 e L2 sejam permutações de uma lista de elementos distintos, sem repetições. Dica: procure auxílio em predicados pré-definidos.
mesmaPosicao(A,[A|_],[A|_]).
mesmaPosicao(A,[_|C1],[_|C2]):-
	mesmaPosicao(A,C1,C2).

%8 - Defina um predicado repete5(E,L) que seja verdadeiro se a lista L for composta por exatamente 5 repetições do elemento E. Não use recursão.
repete5(E,L) :- length(L,5), member(E,L).

%9 - Defina um predicado recursivo sumQuads(L,S) que seja verdadeiro se S for o somatório dos quadrados dos elementos da lista L.
sumQuads([],0).
sumQuads(L,S) :- L=[H|T], sumQuads(T,Aux), S is H*H+Aux.

%10 - Defina um predicado recursivo repete(N,E,L) que seja verdadeiro se a lista L for composta por exatamente N repetições do elemento E.
repete(0,E,[]).
repete(N,E,L) :- L=[E|T], repete(C,E,T), N is C+1.

%11 - Defina um predicado recursivo mapop(L1,L2) que seja verdadeiro se a lista L2 for formada aplicando-se a operação 2*x+1 a cada elemento x da lista L1.
mapop([],[]).
mapop(L1,L2) :- L1=[H|T], mapop(T,Aux), C is 2*H+1, L2 = [C|Aux] .

%12 - Defina um predicado positivos(L1,L2), de forma que L2 seja uma lista só com os elementos positivos de L1.
positivos(L1,L2) :- findall(X,(member(X,L1), X>0), L2).
