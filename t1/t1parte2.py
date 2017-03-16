## 1) Escreva uma funcao que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao inicio de cada nome.
def addSR(lis): 	
	return list(map(lambda x:"Sr."+x,lis))

## 2) Escreva uma funcao que, dada uma lista de numeros, calcule 3n*2 + 2/n + 1 para cada numero n da lista.
def calcula(lis):
	return list(map(lambda n:((3*n*2 + 2)/(n+1)),lis))

## 3) Crie uma funcao que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.
def retornafima(lstring):
	return list(filter(lambda n: n[-1::]=="a",lstring))
	
## 4) Escreva uma funcao que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970. 
##    Para testar a condicao, sua funcao devera subtrair a idade do ano atual.
def apos1970(lis):
	return list(filter(lambda n: (2017-n)>=1970,lis))


## 5) O codigo abaixo e escrito em Python imperativo. Escreva um codigo equivalente usando programacao funcional.

##numbers = [1, 2, 3, 4]
##new_numbers = []
##for number in numbers:
 ##new_numbers.append(number * 2)
##print(new_numbers)

def codigual(lisn):
	return list(map(lambda n: n*2, lisn))
