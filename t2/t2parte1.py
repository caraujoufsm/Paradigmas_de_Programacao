# encoding: utf-8

##1 - Defina uma fun��o addSuffix(suf,nomes) que retorne a lista de nomes com o sufixo suf adicionado###
def addSufix(suf,nome):
    return [x+suf for x in nome]
##2 - Escreva uma fun��o countShorts(words), que receba uma lista de palavras e retorne a quantidade de palavras dessa lista que possuem menos de 5 caracteres.##
def countShorts(words):
    return len([x for x in words if len(x)<5])

##3 - Defina uma fun��o stripVowels(s) que receba uma string e retire suas vogais##
def stripVowels(s):
    return ''.join([x for x in s if x not in 'aeiouAEIOU'])
    
##4 - Defina uma fun��o hideChars(s) que receba uma string, possivelmente contendo espa�os, e que retorne outra string substituindo os demais caracteres por '-', mas mantendo os espa�os.##
def hideChars(s):
    return ''.join([x if x in ' ' else '-' for x in s])

##5 - Defina uma fun��o que receba um n�mero n e retorne uma tabela de n�meros de 1 a n e seus quadrados, conforme os exemplos abaixo (voc� vai usar tuplas em Python):##
def gentable(n):
    return [(x,x**2) for x in range(1,n+1)]

##6 - Defina uma fun��o que receba uma lista de palavras e retorne uma string contendo o primeiro e o �ltimo caracter de cada palavra da lista.##
def gencode(lis):
    return ''.join([x[0]+x[-1] for x in lis])

##7 - Defina uma fun��o myZip(l1,l2) que reproduza o comportamento da fun��o zip do Python##
def myZip(l1,l2):
    return [(l1[x],l2[x]) for x in range(min([len(l1),len(l2)]))]

##8 - Escreva uma fun��o enumerate(words) que numere cada palavra da lista recebida##
def enumerate1(words):
    return [(x+1, words[x]) for x in range(len(words))]

##9 - Escreva uma fun��o isBin(s) que verifique se a string recebida representa um n�mero bin�rio.##
def isBin(s):
    return len(([x for x in s if x=='0' or x=='1']))==len(s)

##10 - Escreva uma fun��o bin2dec(digits), que receba uma lista de d�gitos representando um n�mero bin�rio e retorne seu equivalente em decimal.##
def binDec(x):
        return sum([x[((len(x)-1)-y)]*(2**y) for y in range(len(x))])
