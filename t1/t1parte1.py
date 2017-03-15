## Exercício 1
def somaQuad(x,y): return ((x*x)+(y*y))

## Exercício 2
def hasEqHeads(l1,l2):
	if(l1[0]==l2[0]):
		return True
	else:
		return False

## Exercício 3
## Forma 1
def addstring(x): return "Sr."+x
lis = ["Cassio","Castro","Araujo"]
list(map(addstring,lis))

## Forma 2
def addstring(lista):
	string = "Sr."
	return [string + x for x in lista]

## Exercício 4
def espaco(e): return e in ' '
len(filter(espaco,"Uma string qualquer."))

## Exercício 5
def calcula(n): return ((3*n*2 + 2)/(n+1))
lis = [1,3,5]
list(map(calcula,lis))

## Exercício 6
def negativo(n):return n<0
lis = [-1,2,-3,-8,18]
list(filter(negativo,lis))

## Exercício 7
def estaentre(n): return n>=1 and n<=100
lis = [-1,2,-3,-8,18]
list(filter(estaentre,lis))

## Exercício 8
def epar(n): return n%2==0
lis = [-1,2,-3,-8,18]
list(filter(epar,lis))

	

