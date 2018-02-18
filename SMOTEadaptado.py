#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
from random import randrange, choice
from sklearn.neighbors import NearestNeighbors
import math as mt


def SMOTEadaptado(T, M, k):
    newindex =0; #indice da minha nova matriz
    #T é a matriz que a gente quer fazer oversampling
    #M é a matriz da classe marjoritaria
    #k sao os k vizinhos
    
    d = len(M) - len(T) #20 000 - 350 = 19 650
    N = int(mt.ceil((float(d)/len(T)))) #teto(19 650/350) = 57 e transforma num int
    
    n_minority_samples, n_features = T.shape #pega as dimensoes da matriz T
    print(n_features)
              
    
    n_synthetic_samples = len(M) #quantidade de amostras da classe marjoritaria

    S = np.zeros(shape=(d, n_features)) #faz uma matriz com o tamanho [19 650][48], array Synthetic sample
    
    All = np.concatenate((T, M), axis=0) #junta os dois vetores num só, pois no smote adp vc tem que procurar os vizinhos entre todas as classes
    #aprende quem são os k vizinhos mais proximos e coloca eles em neigh
    neigh = NearestNeighbors(n_neighbors = k) 
    neigh.fit(All)
    
    #Calculate synthetic samples
    
    for i in range(0,n_minority_samples): #faz 350 vezes
        nn = neigh.kneighbors([All[i]], return_distance=False) #pega os indices dos k vizinhos da amostra i, so vai fazer o knn pras primeiras 350 amostras que são justamente da classe minoritaria
        
        for n in xrange(N): #faz ~= 57 vezes
            nn_index = choice(nn[0]) #escolhe dentre um dos vizinhos , nn retorna uma lista de listas por isso uso o indice 0
            
            #Obs: nn inclue T[i] e nos não queremos selecionar ele
            while nn_index == i:
                nn_index = choice(nn[0])
                
            dif = All[nn_index] - T[i]

            #classe minoritaria é a classe 2
            #Se o vizinho for da classe 2 pega um valor aleatorio entre 0 e 1
            #Se não for, pega um valor aleatorio entre 0 e 0.5
            #a ultima coluna representa o ultimo bit do target
            if(All[nn_index][n_features-1] == 0):
                gap = np.random.random() #retorna floats num intervalo de [0,1]
            else:
                gap =  np.random.uniform(0, 0.5)  #retorna floats num intervalo de [0,0.5] 
            
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

SynthArray = SMOTEadaptado(listaC2_treino,listaC1_treino,10) #K ainda tem que ser testado, para ve que valor fica melhor

listaC2_treino_aumentada = np.concatenate((listaC2_treino, SynthArray), axis=0)

np.savetxt('class2_treino_oversampling_SMOTEadaptado.txt', listaC2_treino_aumentada,fmt='%.6f') #coloca no txt

#_______________________________________VALIDACAO__________________________________________________________________________
listaC1_validacao = np.loadtxt('class1_validacao.txt', skiprows=0) #coloca numa lista de floats
listaC2_validacao = np.loadtxt('class2_validacao.txt', skiprows=0) #coloca numa lista de floats

SynthArray2 = SMOTEadaptado(listaC2_validacao,listaC1_validacao,10) #K ainda tem que ser testado, para ve que valor fica melhor

listaC2_validacao_aumentada = np.concatenate((listaC2_validacao, SynthArray2), axis=0)

np.savetxt('class2_validacao_oversampling_SMOTE_adaptado.txt', listaC2_validacao_aumentada,fmt='%.6f') #coloca no txt


#---------------------------------------------------------------------------------------------------------------------------------    