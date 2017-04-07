/*	
		Problema: Férias(http://olimpiada.ic.unicamp.br/passadas/OBI2008/res_fase2_inic/iniciacao_n1/pdf/provas/ProvaOBI2008_inic_f2n1.pdf)
		Seis amigos, A, B, C, D, E e F, querem aproveitar
		suas ferias escolares jogando video-game. Eles v˜ao se
		reunir cada dia na casa de um deles, durante seis dias
		seguidos da semana. Eles n˜ao podem se reunir mais
		de uma vez na casa da mesma pessoa, e as seguintes
		condicoes s˜ao tambem aplicadas:
		- A reuni˜ao na casa de A deve ser imediatamente antes ou imediatamente depois da reuni˜ao na casa de E.
		- Existe exatamente um dia entre os dias das reuni˜oes nas casas de A e B, independentemente se a reuni˜ao na casa de A ocorre antes ou depois da reuni˜ao da casa de B.
		- Se a reuni˜ao na casa de D ocorre antes da reuni˜ao na casa de C, ent˜ao a sexta reuni˜ao e na casa de F.
		- A quarta reuni˜ao ´e na casa de C.
*/

regra1(A) :- 
	nth0(Da, A, a),
	nth0(De, A, e),
	Dif is abs(Da-De),
	Dif = 1.

regra2(A) :- 
	nth0(Da, A, a),
	nth0(Db, A, b),
	Dif is abs(Da-Db),
	Dif = 2.
	
regra3(A) :- A = [d,_,_,c,_,f].
regra3(A) :- A = [_,d,_,c,_,f].
regra3(A) :- A = [_,_,d,c,_,f].
regra3(A) :- A = [_,_,_,c,d,_].
regra3(A) :- A = [_,_,_,c,_,d].

regra4(A) :- A = [_,_,_,c,_,_].

aoLado(X,Y,A) :- nextto(X,Y,A).
aoLado(X,Y,A) :- nextto(Y,X,A).

%regras combinadas
reunioes(A) :-
	A = [_,_,_,_,_,_],
	Amigos = [a,b,c,d,e,f],
	permutation(Amigos, A),
	regra1(A),
	regra2(A),
	regra3(A),
	regra4(A).
	

/*
		Quest˜ao 1. Qual das seguintes opc˜oes e uma lista
		completa e correta da ordem das reuni˜oes da primeira
		a sexta?
		(A) A, F, B, C, D, E
		(B) B, E, A, C, F, D
		(C) D, B, C, A, E, F
		(D) E, A, D, C, B, F
		(E) F, D, B, C, A, E
*/

/*
	?- reunioes([a,f,b,c,d,e]).
	?- reunioes([b,e,a,c,f,d]).
	?- reunioes([d,b,c,a,e,f]).
	?- reunioes([e,a,d,c,b,f]).
	?- reunioes([f,d,b,c,a,e]).
*/

/*
		Quest˜ao 2. Se a reuni˜ao na casa de B e a terceira,
		ent˜ao a reuni˜ao na casa de F pode ser em qualquer uma
		das ordens de qual das opc˜oes abaixo?
		(A) A primeira ou a segunda
		(B) A primeira ou a sexta
		(C) A segunda ou a sexta
		(D) A segunda ou a quinta
		(E) A quinta ou a sexta

	?- reunioes(A),A=[_,_,b,_,_,_].
*/

/*
		Quest˜ao 3. Se a reuni˜ao na casa de B e imediatamente
		antes ou imediatamente depois da reuni˜ao na casa de
		F, ent˜ao qual das seguintes opc˜oes deve ser a ordem da
		reuni˜ao na casa de D?
		(A) A primeira
		(B) A segunda
		(C) A terceira
		(D) A quinta
		(E) A sexta

	?- reunioes(A), aoLado(b,f,A).
*/

/*
		Quest˜ao 4. A segunda reuni˜ao pode ser na casa de:
		(A) A
		(B) B
		(C) D
		(D) E
		(E) F
	
	?- reunioes(A),A=[_,X,_,_,_,_].
*/
	
/*
		Quest˜ao 5. Qual das opc˜oes abaixo e uma lista correta
		e completa de possıveis casas nas quais pode ocorrer a
		terceira reuni˜ao?
		(A) Na casa de A ou B
		(B) Na casa de A, D ou F
		(C) Na casa de B ou E
		(D) Na casa de B, D ou F
		(E) Na casa de C, E ou F

	?- reunioes(A),A=[_,_,X,_,_,_].
*/