# -*- coding: utf-8 -*-
"""
Created on Thu Nov  5 19:31:06 2020

@author: user
"""

import numpy as np
import matplotlib.pyplot as plt

sr = 44100

fft_window_size = 2048 
t = np.arange( fft_window_size )/sr

f = 5000

s = np.sin( 2*np.pi*f*t )

y = np.fft.fft( s )

r = y.real
m = y.imag
# we will mostly need the magnitude of the fft output
# the combination of the real and the imaginary parts give phase information
mag = np.sqrt( r**2 + m**2 )

# y has as many values as the values in the input array (s)
# for the current example 2048
# plt.plot( np.arange( mag.size ) , mag )

# these 2048 divide the range from 0Hz to 44100Hz (sr)
# in equally-spaced intervals
# each interval includes the overall power of the signal 
# in the frequencies it describes
frequency_bins = sr*np.arange( mag.size )/mag.size
# plt.plot( frequency_bins , mag )

# since we don't the aliased part, we just keep the first half
# plt.plot( frequency_bins[:fft_window_size//2] , mag[:fft_window_size//2] )


# in practice, first windowing is applied before fft
f = 100
s = np.sin( 2*np.pi*f*t + np.pi*0.3 )

w = np.hanning( fft_window_size )
plt.plot( np.arange(w.size) , w )
plt.plot( np.arange(s.size) , s )
plt.plot( np.arange(s.size) , w*s )

# inverse fft - ifft
x1 = np.fft.ifft( y )
# we need to keep only the real part
reconstructed_signal = x1.real
# if the initial signal (s) was complex, we would need the imaginary part as well
# since s is real, we only need the real part
# x1.imag is negligible


# frequency bin masking
mask = np.ones( y.shape[0]//2 )
mask[:50] = 0
np.random.shuffle(mask)