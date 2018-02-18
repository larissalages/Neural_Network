#k_means pra fazer o undersampling
#coding: utf-8

import numpy as np
from sklearn.cluster import KMeans
 
 #Para o treino
listaC1_treino = np.loadtxt('class1_treino.txt', skiprows=0) #coloca numa lista de floats
listaC2_treino = np.loadtxt('class2_treino.txt', skiprows=0) #coloca numa lista de floats

n_clusters = len(listaC2_treino) #o numero de clusters vai ser o numero de padroes da classe2, no nosso caso é pra ser 350

k_means = KMeans(n_clusters)
k_means.fit(listaC1_treino)
vClass1_reduzido = k_means.cluster_centers_ #pega os centroids


np.savetxt('class1_treino_kmeans.txt', vClass1_reduzido,fmt='%.6f') #coloca no txt

#Para a Validacao
listaC1_val = np.loadtxt('class1_validacao.txt', skiprows=0) #coloca numa lista de floats
listaC2_val = np.loadtxt('class2_validacao.txt', skiprows=0) #coloca numa lista de floats

n_clusters = len(listaC2_val) #o numero de clusters vai ser o numero de padroes da classe2, no nosso caso é pra ser 350

k_means2 = KMeans(n_clusters)
k_means2.fit(listaC1_val)
vClass1_reduzido_v = k_means2.cluster_centers_ #pega os centroids


np.savetxt('class1_validacao_kmeans.txt', vClass1_reduzido_v,fmt='%.6f') #coloca no txt