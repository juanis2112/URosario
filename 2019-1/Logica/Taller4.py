#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Feb 13 13:56:06 2019

@author: juanis
"""



# Definición de Arbol


class Tree(object):
    def __init__(self, label, iz, der):
        self.left = iz
        self.right = der
        self.label = label


A0 = Tree('p', None, None)
A1 = Tree('q', None, None)
A2 = Tree('-', None, A1)
A = Tree('&', A0, A2)

B0 = Tree('p', None, None)
B1 = Tree('-', None, B0)
B2 = Tree('q', None, None)
B3 = Tree('-', None, B2)
B4 = Tree('&', B0, B3)
B5 = Tree('&', B0, B2)
B6 = Tree('>', B4, B5)
B = Tree('>', B1, B6)


C0 = Tree('p', None, None)
C1 = Tree('-', None, C0)
C2 = Tree('q', None, None)
C3 = Tree('v', C1, C2)
C4 = Tree('r', None, None)
C5 = Tree('-', None, C4)
C6 = Tree('&', C5, C1)
C7 = Tree('v', C0, C4)
C8 = Tree('&', C6, C7)
C9 = Tree('>', C2, C8)
C = Tree('&', C3, C9)


I = {'p': 0, 'q': 1, 'r': 0}

# Funcion V1


def Vi(f, I):
    if f.right == None:
        return I[f.label]
    elif f.label == '-':
        return 1-Vi(f.right, I)
    elif f.label == '&':
        return Vi(f.left, I)*Vi(f.right, I)
    elif f.label == 'v':
        return max(Vi(f.left, I), Vi(f.right, I))
    elif f.label == '>':
        return max(1-Vi(f.left, I), Vi(f.right, I))
    elif f.label == 'sii':
        return 1-(Vi(f.left, I)-Vi(f.right, I)) ^ 2


# Ejercicio 1

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

# La función crea una lista con todas las posibles combinaciones de
# interpretaciones para las 4 listas proposicionales

# Ejercicio 2


def WhichType(A, letrasProposicionales):
    interps = Interps(letrasProposicionales)
    Values = []
    i = 0
    Suma = 0
    while i < len(interps):
        I = interps[i]
        Values.append(Vi(A, I))
        Suma = Suma + Vi(A, I)
        i += 1
    if Suma == 0 :
        Type = 'Insatisfacible'
    elif Suma == len(interps):
        Type = 'Valida'
    else:
        Type = 'Contingente'
    return Values, Suma, Type

# Arboles
    
A0 = Tree('p', None, None)
A1 = Tree('q', None, None)
A2 = Tree('-', None, A0)
A3 = Tree('>', A2, A1)
A = Tree('>', A0, A3)

B = Tree('&', A2, A1)

C0 = Tree('p', None, None)
C1 = Tree('q', None, None)
C2 = Tree('-', None, C0)
C3 = Tree('-', None, C1)
C4 = Tree('>', C2, C3)
C5 = Tree('&', C2, C4)
C = Tree('&', C5, C1)



