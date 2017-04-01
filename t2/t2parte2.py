#!/usr/bin/env python3
import itertools
import random

'''
   Programacao funcional para gerar SVG:
   - gera uma lista de coordenadas de retangulos
   - define uma lista de estilos (cores), em qualquer quantidade
   - aplica os estilos aos retangulos, gerando uma lista com todos os dados para o SVG
   - coloca os dados no formato SVG, concatenando strings
'''

def geracor(n):
   return ["fill:rgb("+str(random.sample(range(144),2))+","+str(random.randrange(144,256,2))+")" for n in range(n)]

def svgRect(rs):
   (((x,y),w,h),style) = rs
   return "<rect x='%.3f' y='%.3f' width='%.2f' height='%.2f' style='%s'/>\n" % (x,y,w,h,style)

def svgImage(w, h, rs):
   return "<svg width='%.2f' height='%.2f' xmlns='http://www.w3.org/2000/svg'>\n" % (w,h) + \
          ''.join(map(svgRect, rs)) + "</svg>"

def applyStyles(rects, styles):
   return list(zip(rects, itertools.cycle(styles)))

def genRects(n, w, h):
   return [((x*w,0),w,h) for x in list(reversed(range(n)))]

def writeFile(fname, contents):
   f = open(fname, 'w')
   f.write(contents)
   f.close()

def main():
   maxWidth = 1000
   maxHeight = 100
   n = 10
   rects = genRects(n,50,50)
   #cria uma lista de str contendo os valores rgb
   styles = geracor(n)
   rectstyles = applyStyles(rects, styles)
   writeFile("minhascores.svg", svgImage(maxWidth, maxHeight, rectstyles))
   

if __name__ == '__main__':
   main()
