# 1. Considere a seguinte base de fatos e regras:
```prolog
pai(roberto,joao).
pai(joao, jose).
pai(roberto,julio).
pai(julio,marcos).
pai(julio,mario).
avo(X,Z) :- pai(X,Y), pai(Y,Z).
```
Mostre o trace comentado das consultas:
```
?- avo(joao,Y).
false.
?- avo(roberto,Y).
Y = jose ;
Y = marcos ;
Y = mario.
```
?- trace.
true.
## ------------------------------------PARTE 1--------------------------------------------
```prolog
[trace]  ?- avo(joao,Y).
   Call: (8) avo(joao, _584) ? creep % Fez a chamada e o sistema atribuiu _584 como Y 
   Call: (9) pai(joao, _802) ? creep % Criou uma nova variavel e chamou a função pai com o joao para saber quem é filho dele. Atribuiu _802 como uma variavel 
   Exit: (9) pai(joao, jose) ? creep % Retornou a variavel a chamada anterior com _802 = jose. joao é pai do jose. 
   Call: (9) pai(jose, _584) ? creep % Chamou a funcao para saber de quem jose é pai. Usando o _584 como variavel 
   Fail: (9) pai(jose, _584) ? creep % Retornou erro pois o jose nao tem filho 
   Fail: (8) avo(joao, _584) ? creep % Retornou erro pois joao nao tem netos, pois jose nao tem filho 
false.	% Retornou falso.
```
## -------------------------------------PARTE 2--------------------------------------------
```prolog
[trace]  ?- avo(roberto,Y).
   Call: (8) avo(roberto, _584) ? creep   % Fez a chamada e o sistema atribuiu _584 como Y 
   Call: (9) pai(roberto, _804) ? creep   % Criou uma nova variavel e chamou a funcao pai com roberto para saber quem é filho dele. Atribuiu _804 como uma variavel 
   Exit: (9) pai(roberto, joao) ? creep   % Retornou a variavel _804 = joao. roberto é pai de joao. 
   Call: (9) pai(joao, _584) ? creep	  % Fez uma chamada da funcao pai passando joao como parametro. 
   Exit: (9) pai(joao, jose) ? creep	  % Recebeu jose como retorno. Logo jose e filho de joao 
   Exit: (8) avo(roberto, jose) ? creep   % Recebeu como retorno que roberto é avo de jose 
Y = jose ;	% Resposta 
   Redo: (9) pai(roberto, _804) ? creep   % Fez uma nova chamada para saber se roberto tem mais filhos 
   Exit: (9) pai(roberto, julio) ? creep  % Retornou julio como filho de roberto 
   Call: (9) pai(julio, _584) ? creep	  % Fez uma chamada para saber de quem julio e pai 
   Exit: (9) pai(julio, marcos) ? creep	  % Retornou que marcos e filho de julio 
   Exit: (8) avo(roberto, marcos) ? creep % Recebeu como retorno que roberto é avo de marcos 
Y = marcos ;    % Resposta 
   Redo: (9) pai(julio, _584) ? creep	  % Fez uma nova chamada para saber se julio tem mais filhos 
   Exit: (9) pai(julio, mario) ? creep	  % Retornou que mario e filho de julio 
   Exit: (8) avo(roberto, mario) ? creep  % Recebeu como retorno que mario também é neto de roberto 
Y = mario.	% Resposta 
```
# 2.Considere o predicado definido abaixo, que resolve um problema de uma prova da Olimpíada Brasileira de Informática.
```prolog
azulejos(0,0).
azulejos(Na,Nq) :-
   Na > 0,
   Q is floor(sqrt(Na)),
   R is Na - Q*Q,
   azulejos(R,C),
   Nq is 1 + C.
```
Mostre o trace comentado desta consulta:
```
?- azulejos(120,A).
```
```prolog
[trace]  ?- azulejos(120,A).
   Call: (8) azulejos(120, _584) ? creep		% Chamou a função azulejos passando 120 como Na 
   Call: (9) 120>0 ? creep				% Verifica se 120>0 
   Exit: (9) 120>0 ? creep				% Sai da chamada e segue para a proxima parte 
   Call: (9) _808 is floor(sqrt(120)) ? creep		% Pega o maior inteiro menor ou igual ao resultado do sqrt 
   Exit: (9) 10 is floor(sqrt(120)) ? creep		% Retorna 10 como o valor e atribui a Q 
   Call: (9) _820 is 120-10*10 ? creep			% Chama a função R is Na - Q*Q 
   Exit: (9) 20 is 120-10*10 ? creep			% R recebe o valor da função acima, no caso 20 
   Call: (9) azulejos(20, _822) ? creep			% Chama a funcao azulejos passando R = 20 como parametro 
   Call: (10) 20>0 ? creep				% Verifica se 20>0 
   Exit: (10) 20>0 ? creep				% Sai da chamada e segue para a proxima parte 
   Call: (10) _828 is floor(sqrt(20)) ? creep		% Pega o maior inteiro menor ou igual ao resultado do sqrt 
   Exit: (10) 4 is floor(sqrt(20)) ? creep		% Retorna 4 como valor e atribui a Q 
   Call: (10) _840 is 20-4*4 ? creep			% Chama a funcao R is Na - Q*Q 
   Exit: (10) 4 is 20-4*4 ? creep			% R recebe o valor da funcao acima, no caso 4 
   Call: (10) azulejos(4, _842) ? creep			% Chama a funcao azulejos passando R = 4 como parametro 
   Call: (11) 4>0 ? creep				% Verifica se 4>0 
   Exit: (11) 4>0 ? creep				% Sai da chamada e vai para a proxima parte 
   Call: (11) _848 is floor(sqrt(4)) ? creep		% Pega o maior inteiro menor ou igual ao resultado do sqrt 
   Exit: (11) 2 is floor(sqrt(4)) ? creep		% Retorna 2 como o valor e atribui a Q 
   Call: (11) _860 is 4-2*2 ? creep			% Chama a funcao R is Na - Q*Q 
   Exit: (11) 0 is 4-2*2 ? creep			% R recebe o valor da funcao acima, no caso 0 
   Call: (11) azulejos(0, _862) ? creep			% Chama a funcao azulejos passando 0 como Na 
   Exit: (11) azulejos(0, 0) ? creep			% Entrou no fato que azulejos(0,0) 
   Call: (11) _866 is 1+0 ? creep			% Chama a funcao Nq is 1 + C 
   Exit: (11) 1 is 1+0 ? creep				% Retorna 1 como resultado e atribui a Nq 
   Exit: (10) azulejos(4, 1) ? creep			% Cria o fato que azulejos(4,1) 
   Call: (10) _872 is 1+1 ? creep			% Chama a funcao Nq is 1 + C 
   Exit: (10) 2 is 1+1 ? creep				% Retorna 2 como resultado e atribui a Nq 
   Exit: (9) azulejos(20, 2) ? creep			% Retorna o fato que azulejos(20,2) 
   Call: (9) _584 is 1+2 ? creep			% Chama a funcao Nq is 1 + C 
   Exit: (9) 3 is 1+2 ? creep				% Retorna 3 como resultado e atribui a Nq 
   Exit: (8) azulejos(120, 3) ? creep			% Cria o fato que azulejos(120,3) 
A = 3 .							% Resposta final = 3 
```

# 3. Escolha algum predicado recursivo que esteja nos slides ou em qualquer outra fonte.Faça a execução passo-a-passo de uma consulta com o predicado escolhido. Lembre-se de mostrar o código do predicado no seu arquivo t3parte1.md
```prolog
fat(0,1).
fat(N,F) :-
	N > 0,
	Aux is N-1,
	fat(Aux, M),
	F is N*M
```
```prolog	
[trace]  ?- fat(3,F).
   Call: (8) fat(3, _584) ? creep		% Chamou a funcao fat passando 3 como parametro
   Call: (9) 3>0 ? creep			% Verifica se 3>0 
   Exit: (9) 3>0 ? creep			% Segue para a proxima parte 
   Call: (9) _808 is 3+ -1 ? creep		% Chama a funcao Aux is N - 1 
   Exit: (9) 2 is 3+ -1 ? creep			% Armazena o resultado em Aux 
   Call: (9) fat(2, _810) ? creep		% Chama a funcao fat passando Aux = 2 como parametro 
   Call: (10) 2>0 ? creep			% Verifica se 2>0 
   Exit: (10) 2>0 ? creep			% Segue para a proxima parte 
   Call: (10) _814 is 2+ -1 ? creep		% Chama a funcao Aux is N - 1 
   Exit: (10) 1 is 2+ -1 ? creep		% Armazena o resultado em Aux 
   Call: (10) fat(1, _816) ? creep		% Chama a funcao fat passando Aux = 1 como parametro 
   Call: (11) 1>0 ? creep			% Verifica se 1>0 
   Exit: (11) 1>0 ? creep			% Segue para a proxima parte 
   Call: (11) _820 is 1+ -1 ? creep		% Chama a funcao Aux is N - 1 
   Exit: (11) 0 is 1+ -1 ? creep		% Armazena o resultado em Aux 
   Call: (11) fat(0, _822) ? creep		% Chama a funcao fat passando Aux = 0 como parametro 
   Exit: (11) fat(0, 1) ? creep			% Achou um fato que fat(0,1) 
   Call: (11) _826 is 1*1 ? creep		% Chama a funcao F is N*M passando 1 e 1 
   Exit: (11) 1 is 1*1 ? creep			% Recebe 1 como resultado 
   Exit: (10) fat(1, 1) ? creep			% Cria um fato que fat(1,1) 
   Call: (10) _832 is 2*1 ? creep		% Chama a funcao F is N*M passando 2 e 1 
   Exit: (10) 2 is 2*1 ? creep			% Recebe 2 como resultado 
   Exit: (9) fat(2, 2) ? creep			% Cria um fato que fat(2,2) 
   Call: (9) _584 is 3*2 ? creep		% Chama a funcao F is N*M passando 3 e 2 
   Exit: (9) 6 is 3*2 ? creep			% Recebe 6 como resultado 
   Exit: (8) fat(3, 6) ? creep			% Cria o fato que fat(3,6) 
F = 6 						% Resposta da questao 
```
