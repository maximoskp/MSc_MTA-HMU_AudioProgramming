# -*- coding: utf-8 -*-
"""
Created on Thu Oct 29 19:50:12 2020

@author: user
"""

import numpy as np
import matplotlib.pyplot as plt

sr = 44100
t = np.arange(0, sr)/sr

# x = np.interp( t , (0 , 0.9) , (0, 324) )

f = 5
s = np.sin( 2*np.pi*f*t )

# plt.plot( t , s )

x = np.interp( s , (-1,1) , (0,4) )
q = np.floor( x )
q[ q >= 4 ] = 3

# original signal - before quantization
plt.plot( t , x )
# quantized signal - what the system can capture
plt.plot( t , q )
# quantization noise
plt.plot( t , x-q )



'''
# indexing in numpy
y = np.array([1,2,3,4])
yy = y > 2
y[ y > 2 ] = 100
'''

sr = 44100
t = np.arange(4096)/44100
f = 190
s = np.sin( 2*np.pi*f*t )
plt.plot( t , s )