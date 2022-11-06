#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 31 18:27:48 2022

@author: max
"""

import numpy as np

sr = 44100
f = 150
amp = 0.5
dur = 2

t = np.arange(dur*sr)/sr

s0 = amp*np.sin( 2*np.pi* f *t )

# %% 

s1 = (amp/2)*np.sin( 2*np.pi* 2*f *t )
s2 = (amp/4)*np.sin( 2*np.pi* 3*f *t )
s3 = (amp/8)*np.sin( 2*np.pi* 4*f *t )

s = s0 + s1 + s2 + s3

# %% 

import matplotlib.pyplot as plt

plt.plot(t , s)
plt.plot(t , s0)
plt.plot(t , s1)
plt.plot(t , s2)
plt.plot(t , s3)

# %% 

import sounddevice as sd
import time # για παύση ανάμεσα στις αναπαραγωγές

sd.play( s0, 44100 )
print('playing s0')
time.sleep(dur + 0.1)
sd.play( s0+s1, 44100 )
print('playing s0+s1')
time.sleep(dur + 0.1)
sd.play( s0+s1+s2, 44100 )
print('playing s0+s1+s2')
time.sleep(dur + 0.1)
sd.play( s, 44100 )
print('playing s')

# %% for tutorial

for x in ['apple', 'orange', 6, 33.1]:
    print(x)

r = range(10)
l = list( r )

# %% 

sr = 44100
f = 150
amp = 0.5
dur = 2

t = np.arange(dur*sr)/sr

s = amp*np.sin( 2*np.pi * f * t )

for i in range(100):
    s = s + ( amp / ( 2**(i+1) ) )*np.sin( 2*np.pi * (i+2)*f * t )

plt.plot( t, s )
