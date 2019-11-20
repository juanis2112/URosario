# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

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
    
      
def Regla1(LetrasProposicionales):       
    conjunciones = ''
    inicial= True
    for p in LetrasProposicionales:
        aux1 = [x for x in LetrasProposicionales if x != p] # Todas las letras excepto p 
        for q in aux1:
            aux2 = [x for x in aux1 if x != q] # Todas las letras excepto p y q 
            for r in aux2:
                literal = r + q + p + 'Y'+'Y'
                aux3 = [x + '-' for x in aux2 if x != r]
                for k in aux3:
                    literal = k + literal + 'Y'
                if inicial: # Inicializar la primera conjuncion
                    conjunciones = literal
                    inicial = False 
                else:
                    conjunciones = literal + conjunciones + 'O'
    return conjunciones

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

LetrasProposicionales= ['1','2','3','4','5','6','7','8','9']

Regla1 = Regla1(LetrasProposicionales)
Regla2 = '(8-6-Y1>)'+'(9-7-Y2>)'+'(8-4-Y3>)'+'(9-3-Y4>)'+'(7-1-Y6>)'+'(6-2-Y7>)'+'(3-1-Y8>)'+'(4-2-Y9>)'+'YYYYYYY'
Regla3= '26Y'

Reglas = Regla1+Regla2+Regla3+'Y'+'Y'

# Aca empieza el programa


interps = Interps(LetrasProposicionales)
formula = String2Tree(Reglas, LetrasProposicionales)
interpsTrue = [] 
for i in interps:
    if (Vi(formula, i) == 1):
        interpsTrue.append(i)
    
formulas=[]
for dic in interpsTrue:
    formula=[]
    for i in LetrasProposicionales:
        if dic[i]==1:
            formula.append(i)
        if dic[i]==0:
            formula.append('-'+i)
        
    formulas.append(formula)
            
        
    








