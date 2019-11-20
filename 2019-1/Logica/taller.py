#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Feb  6 14:39:05 2019

@author: juanis
"""

def factorial(n):
    if n==0:
        return 1
    else:
        return n*factorial(n-1)


#n = input("Entre un numero")
#n = int(n)

#print("El factorial es:", factorial(n))


def suma(n):
    if n==0:
        return 0
    else:
        return n+suma(n-1)
#n= input("Entre un numero")
#n=int(n)

#print("La suma es:", suma(n))


def potencia_de_2(n):
    if n==0:
        return 1
    else:
        return 2*potencia_de_2(n-1)

#print("La potencia es:", potencia_de_2(n))


class Tree(object):
    def __init__(self,iz,der):
        self.left=iz
        self.right=der
        
Hoja = Tree(None,None)
Rama = Tree(Hoja, Hoja)
Arbol1 = Tree(Rama, Hoja)
Arbol2 = Tree(Hoja, Rama)
Arbol3 = Tree(Rama, Rama)

Arb = Arbol1
Arb2 = Tree(Arbol1, Arbol3)


if Arb.left == None:
    print("Hoja")
else:
    print("Rama")

def numHojas(Arb):
    if Arb.left==None:
        return 1
    else:
        return numHojas(Arb.left) + numHojas(Arb.right)


def Vertices(Arb):
    if Arb.left==None:
        return Arb
    else:
        return (Arb, Vertices(Arb.left), Vertices(Arb.right)) 

def Vertices2(Arb):
    if Arb.left==None:
        return 1
    else:
        return (1, Vertices2(Arb.left), Vertices2(Arb.right)) 



