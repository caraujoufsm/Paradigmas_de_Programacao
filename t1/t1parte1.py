## 1) Defina uma funcao somaQuad(x,y) que calcule a soma dos quadrados de dois numeros x e y.
def somaQuad(x,y): return ((x*x)+(y*y))

## 2) Crie uma funcao hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.
def hasEqHeads(l1,l2):
	if(l1[0]==l2[0]):
		return True
	else:
		return False

## 3) Escreva uma funcao que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao inicio de cada nome. Defina uma funcao auxiliar para ajudar neste exercicio.
## Forma 1
def aux3(x): return "Sr."+x
def addstring1(lis): 
	return list(map(aux3,lis))

## Forma 2
def addstring2(lista):
	string = "Sr."
	return [string + x for x in lista]

## 4) Crie uma funcao que receba uma string e retorne o numero de espacos nela contidos. Defina uma funcao auxiliar para ajudar neste exercicio.
def aux4(e): 
	return e in ' '
def espaco(string): 
	return len(filter(aux4,string))

## 5) Escreva uma funcao que, dada uma lista de numeros, calcule 3n*2 + 2/n + 1 para cada numero n da lista. Defina uma funcao auxiliar para ajudar neste exercicio.
def aux5(n): 
	return ((3*n*2 + 2)/(n+1))
def calcula(lis):
	return list(map(aux5,lis))

## 6) Escreva uma funcao que, dada uma lista de numeros, retorne uma lista com apenas os que forem negativos. Defina uma funcao auxiliar para ajudar neste exercicio.
def aux6(n):
	return n<0
def negativo(lis): 
	return list(filter(aux6,lis))

## 7) Escreva uma funcao que receba uma lista de numeros e retorne somente os que estiverem entre 1 e 100, inclusive. Defina uma funcao auxiliar para ajudar neste exercicio.
def aux7(n): 
	return n>=1 and n<=100
def estaentre(lis): 
	return list(filter(aux7,lis))

## 8) Escreva uma funcao que receba uma lista de numeros e retorne somente aqueles que forem pares. Defina uma funcao auxiliar para ajudar neste exercicio.
def aux8(n): 
	return n%2==0
def epar(lis): 
	return list(filter(aux8,lis))

## 9) Crie uma funcao charFound(c,s) que verifique se o caracter c esta contido na string. O resultado deve ser True ou False. Voce nao deve usar o operador in. Defina uma funcao auxiliar para ajudar neste exercicio.
# Forma 1
def charFound1(c,s): 
	if (s.find(c)>=0): 
		return True
	else: 
		return False	

# Forma 2
def charFound(c,s):
	def charaux(s):
		return c==s
	if(len(filter(charaux,s))>0):
		return True
	else:
		return False

# Forma 3 (Professora)
def f(c):
	def g(x):
		return c==x
	return g
	
def charFound3(c,lis):
	return len(filter(f(c),lis))	
	
## 10) Escreva uma funcao que receba uma lista de strings e retorne uma nova lista com adicao de marcacoes HTML (p.ex.: <B> e </B>) antes e depois de cada string.
def addhtml(x): return "<p>"+x+"</p>"
def exer10(lis): 
	return list(map(addhtml,lis))
