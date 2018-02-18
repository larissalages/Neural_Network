#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
from random import randrange, choice
from sklearn.neighbors import NearestNeighbors
import math as mt


def SMOTE(T, M, k):
    newindex =0; #indice da minha nova matriz
    #T é a matriz que a gente quer fazer oversampling
    #M é a matriz da classe marjoritaria
    #k sao os k vizinhos
    
    d = len(M) - len(T) #20 000 - 350 = 19 650
    N = int(mt.ceil((float(d)/len(T)))) #teto(19 650/350) = 57 e transforma num int
    
    n_minority_samples, n_features = T.shape #pega as dimensoes da matriz T
                
    #N = N/100 #=~57
    #n_synthetic_samples = N * n_minority_samples #quantidade de amostras da outra classe
    n_synthetic_samples = len(M) #quantidade de amostras da classe marjoritaria

    S = np.zeros(shape=(d, n_features)) #faz uma matriz com o tamanho [19 650][48], array Synthetic sample
    
    #aprende quem são os k vizinhos mais proximos e colocar eles em neigh
    neigh = NearestNeighbors(n_neighbors = k) 
    neigh.fit(T)
    
    #Calculate synthetic samples
    
    for i in range(0,n_minority_samples): #faz 350 vezes
        nn = neigh.kneighbors([T[i]], return_distance=False) #pega os k vizinhos da amostra i
        
        for n in xrange(N): #faz ~= 57 vezes
            nn_index = choice(nn[0]) #escolhe dentre um dos vizinhos , nn retorna uma lista de listas por isso uso o indice 0
            
            #Obs: nn inclue T[i] e nos não queremos selecionar ele
            while nn_index == i:
                nn_index = choice(nn[0])
                
            dif = T[nn_index] - T[i]
            gap = np.random.random() #retorna floats num intervalo de [0,1]
            #S[n + i * N, :] = T[i,:] + gap * dif[:]
            S[newindex] = T[i] + gap*dif
            #Seta pra ser da classe 2 (10)
            S[newindex][n_features-2] = 1#penultima coluna
            S[newindex][n_features-1] = 0 #ultima coluna 
            newindex = newindex +1; 
            if(newindex >= d): #Se atingiu o numero maximo de amostras que precisamos fazer, sai da funcao
                return S

    
    return S
#-----------------------------------------------------------------------------------------------------------------------------
#main
#_________________________________________TREINO__________________________________________________________________________
listaC1_treino = np.loadtxt('class1_treino.txt', skiprows=0) #coloca numa lista de floats
listaC2_treino = np.loadtxt('class2_treino.txt', skiprows=0) #coloca numa lista de floats

SynthArray = SMOTE(listaC2_treino,listaC1_treino,10) #K ainda tem que ser testado, para ve que valor fica melhor

listaC2_treino_aumentada = np.concatenate((listaC2_treino, SynthArray), axis=0)

np.savetxt('class2_treino_oversampling_SMOTE.txt', listaC2_treino_aumentada,fmt='%.6f') #coloca no txt

#_______________________________________VALIDACAO__________________________________________________________________________
listaC1_validacao = np.loadtxt('class1_validacao.txt', skiprows=0) #coloca numa lista de floats
listaC2_validacao = np.loadtxt('class2_validacao.txt', skiprows=0) #coloca numa lista de floats

SynthArray2 = SMOTE(listaC2_validacao,listaC1_validacao,10) #K ainda tem que ser testado, para ve que valor fica melhor

listaC2_validacao_aumentada = np.concatenate((listaC2_validacao, SynthArray2), axis=0)

np.savetxt('class2_validacao_oversampling_SMOTE.txt', listaC2_validacao_aumentada,fmt='%.6f') #coloca no txt

#---------------------------------------------------------------------------------------------------------------------------------    