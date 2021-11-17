# -*- coding: utf-8 -*-

# lists in python
x = [1,2,3]
y = [4,5,6]
z = x + y

# %% numpy
import numpy as np

a = np.array( x )
b = np.array( y )
c = a + b

# %% 2d array
x = [ [1,2,3] , [4,5,6], [7,8,9], [2,4,6] ]
a = np.array( x )

# %% indexing
n = a[2,1]
b = a[2:, :1]

# %% arrays in functions
# y = a**2-5
y = np.sin(a*2*np.pi)

# %%
import sounddevice as sd
import matplotlib.pyplot as plt

t = np.arange(1024)/44100
s = np.sin(2*np.pi*440*t)

plt.plot(t, s, '.')

sd.play(s, 44100)

# %% 

fs = 44100
t = np.arange(1024)/fs
freq = 5000
x = np.sin( 2*np.pi*freq*t )
y = np.fft.fft( x )

y_real = y.real
y_imag = y.imag

a = np.angle(y)

plt.plot(a)