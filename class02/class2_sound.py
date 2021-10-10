#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 22 20:27:25 2020

@author: max
"""

import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd

sr = 1000

t = np.arange(sr)/sr

# s = np.sin(t)
# s = np.power( t, 2 )

# frequency
f = 250 # check aliasing, e.g. f = 750
# amplitude
a = 0.8
# phase
p = 0

s = a*np.sin( 2*np.pi*f*t + p*2*np.pi )

plt.plot( t , s )

sd.play( s , sr )
