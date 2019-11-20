#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar  8 14:36:46 2019

@author: juanis
"""
LetrasProposicionales= ['1','2','3','4','5','6','7','8','9','A','B','C','p','q','r','s']


class Tree(object):
    def __init__(self, label, iz, der):
        self.left = iz
        self.right = der
        self.label = label
        

def Interps(letrasProposicionales):

    interps = []  # Posibles interpretaciones
    aux = {}  # Primera interpretación
    for a in letrasProposicionales:
        aux[a] = 1  # Inicializar primera interpretación con todo verdadero

    interps.append(aux)

    for a in letrasProposicionales:
        interps_aux = [i for i in interps]  # Lista de nuevas interpretaciones

        for i in interps_aux:
            aux1 = {}  # Diccionario auxiliar para crear nueva interpretación

            for b in letrasProposicionales:
                if a == b:
                    aux1[b] = 1 - i[b]  # Cambia el valor de verdad para b
                else:
                    aux1[b] = i[b]  # Cambia el valor para b y mantiene el valor 
                                    # para las otras letras

            interps.append(aux1)  # Incluye la nueva interpretación en la lista

    return interps

def String2Tree(A, LetrasProposicionales):
    #Crea una forula como tree dada una formula como cadena escrita en notacion polaca inversa
    #Input: A, lista de caracteres con una formula escrita en notacion polaca inversa
        #letrasProposicionales: Lista de letras proposicionales
        #Output: Formula como tree
    conectivos = ['O', 'Y', '>']
    pila = []
    for c in A:
        if c in LetrasProposicionales:
            pila.append(Tree(c, None, None))
        elif c =='-':
            formulaAux = Tree(c, None, pila[-1])
            del pila[-1]
            pila.append(formulaAux)
        elif c in conectivos:
            formulaAux = Tree(c, pila[-1], pila[-2])
            del pila[-1]
            del pila[-1]
            pila.append(formulaAux)
            
    
    return pila[-1]

def Vi(f, I):
    if f.right == None:
        return I[f.label]
    elif f.label == '-':
        return 1-Vi(f.right, I)
    elif f.label == 'Y':
        return Vi(f.left, I)*Vi(f.right, I)
    elif f.label == 'O':
        return max(Vi(f.left, I), Vi(f.right, I))
    elif f.label == '>':
        return max(1-Vi(f.left, I), Vi(f.right, I))
    elif f.label == 'sii':
        return 1-(Vi(f.left, I)-Vi(f.right, I)) ^ 2

def inorder(A):
    conectivos = ['O', 'Y', '>']
    if A.right == None:
        return A.label
    elif A.label == "-":
        return '-'+ inorder(A.right)
    elif A.label in conectivos:
        return '(' + inorder(A.left) + A.label + inorder(A.right) + ')'
""" 
PUNTO 1

A)

    1 --> Martes 7-9 Logica 1
    2 --> Miercoles 7-9 Logica 1
    3 --> Jueves 7-9 Logica 1
    4 --> Martes 9-11 Logica 1
    5 --> Miercoles 9-11 Logica 1
    6 --> Jueves 9-11 Logica 1
    7 --> Martes 7-9 Logica 2
    8 --> Miercoles 7-9 Logica 2
    9 --> Jueves 7-9 Logica 2
    A --> Martes 9-11 Logica 2
    B --> Miercoles 9-11 Logica 2
    C --> Jueves 9-11 Logica 2
    
B)    
    --------------------------------
                Logica 1    Logica 2
    --------------------------------        
    Kurt        p           q
    Bertrand    r           s
    --------------------------------

C) (p>-r) Y (-r>p)

Regla1= "p-r>r-p>Y"

D) 

1Y2Y-3Y-4Y-5Y-6 ----- YYYYY12-3-4-5-6 -- 6-5-4-3-21YYYYY
1Y3Y-2Y-4Y-5Y-6 
1Y4Y-2Y-3Y-5Y-6 
1Y5Y-2Y-3Y-4Y-6
1Y6Y-3Y-4Y-5Y-6 

2Y3Y-1Y-4Y-5Y-6 
2Y4Y-1Y-3Y-5Y-6 
2Y5Y-1Y-3Y-4Y-6 
2Y6Y-1Y-3Y-4Y-5

3Y4Y-1Y-2Y-4Y-5 
3Y5Y-1Y-2Y-4Y-6 
3Y6Y-1Y-2Y-4Y-5

4Y5Y-1Y-2Y-3Y-6 
4Y6Y-1Y-2Y-3Y-5  

5Y6Y-1Y-2-3Y-4Y

E)

1>-4 
4>-1
2>-5
5>-2
3>-6
6>-3

OOOOO>1-4>4-1>2-5>5-2>3-6>6-3

3-6>6-3>2-5>5-2>1-4>4-1>00000

F) q>-A 
   q>-C
Y>q-A>q-C
C-q>A-q>Y

   p>-4 
   p>-6

    

    
    

"""
Regla1a= 'pr->r-p>Y'
Regla1b= 'qs->s-q>Y'

Letrasa={'1','2','3','4','5','6'}
Letrasb={'7','8','9','A','B','C'}
def Regla2(Letras):       
    conjunciones = ''
    inicial= True
    for p in Letras:
        aux1 = [x for x in Letras if x != p] # Todas las letras excepto p 
        for q in aux1:
            literal =q + p + 'Y'
            aux2 = [x + '-' for x in aux1 if x != q]
            for k in aux2:
                literal = k + literal + 'Y'
            if inicial: # Inicializar la primera conjuncion
                conjunciones = literal
                inicial = False 
            else:
                conjunciones = literal + conjunciones + 'O'
    return conjunciones


Regla2a=Regla2(Letrasa)
Regla2b=Regla2(Letrasb)

Regla3a='3-6>6-3>2-5>5-2>1-4>4-1>OOOOO'
Regla3b='7-A>A-7>8-B>B-8>9-C>C-9>OOOOO'

Regla4a='C-q>A-q>Y'
Regla4b='6-p>4-p>Y'
Regla4c='8-s>C-s>Y'
Regla4d='2-r>6-r>Y'

Reglas = Regla1a+Regla1b+Regla2a+Regla2b+Regla3a+Regla3b+Regla4a+Regla4b+Regla4c+Regla4d+'YYYYYYYYY'

interps = Interps(LetrasProposicionales)
formula = String2Tree(Reglas, LetrasProposicionales)
interpsTrue = [] 
for i in interps:
    if (Vi(formula, i) == 1):
        interpsTrue.append(i)
    
formulas=[]
t=0
for dic in interpsTrue:
    formula=[]
    for i in LetrasProposicionales:
        if dic[i]==1:
            formula.append(i)
    t=t+1   
    formulas.append(formula)
print(t)



    

    


