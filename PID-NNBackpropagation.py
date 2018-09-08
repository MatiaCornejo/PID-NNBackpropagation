#!/usr/bin/env python
# coding: utf-8

# # PID-NNBackpropagation
# #### Control y modelamiento de PID a travez de redes neuronales con algoritmo Backpropagation

# #### Neurona

# In[1]:


class neurona:
    def __init__(self,cant,nmbr):
        self.peso = cant
        self.nombre = nmbr
    def __conexionAnterior__(self,neurona):
        self.anterior = neurona
    def __conexionSiguiente__(self,neurona):
        self.siguiente = neurona
    def __cambiarPeso__(self,valor):
        self.peso =valor    
    def __str__(self):
        return "Mi Nombre es {0}\nConexion Anterior {1}\nMi Peso es {2}".format(self.nombre,self.anterior.nombre,self.peso)


# #### Red Neuronal

# In[2]:


class red:
    def __init__(self,cant):
        self.neuralnetwork=0
        #definir cantidad de neuronas que participaran en la red


# # PRUEBA DE NEURONAS

# In[3]:


neu=neurona(3,"P")
neu2=neurona(3,"I")
neu2.__conexionAnterior__(neu)
print neu2.__str__()

