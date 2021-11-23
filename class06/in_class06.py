# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import numpy as np
import matplotlib.pyplot as plt

import sounddevice as sd

sr = 44100

t = np.arange( sr )/sr

freq = 5000

y = np.sin( 2*np.pi*freq*t )

# plt.plot( t , s , '.-' )

sd.play( y , sr )

# %% fft 
def plot_fft( s, sample_rate=44100 ):
    # 1) isolate a number of samples from the waveform
    # that can can be expressed as a power of 2, e.g. 1024
    s_for_fft = s[:1024]
    
    # 2) apply hanning window
    w = np.hanning( 1024 )
    
    windowed_signal = w * s_for_fft
    '''
    plt.plot(s_for_fft, 'y')
    plt.plot(w, 'r')
    plt.plot(windowed_signal)
    '''
    
    # 3) compute fft
    y = np.fft.fft( windowed_signal )
    # y comprises complex numbers
    # complex numbers incorporate a real
    y_real = y.real
    # and an imaginary part
    y_imag = y.imag
    
    # 4) get power spectrum
    mag = np.sqrt( y_real**2 + y_imag**2 )
    
    
    freqs = np.linspace(0, sample_rate/2, len(mag)//2)
    plt.plot( freqs, mag[:len(mag)//2] )
# plot_fft

# %% 

plot_fft(y)

# %% 

plt.plot(t,y)

import copy
q = copy.deepcopy(y)

# ό,τι είναι πάνω από 0, κάν΄το 1
q[ q >= 0 ] = 1
q[ q < 0 ] = -1

plt.plot(t,q)

sd.play(q, sr)

plot_fft(q)

# %%

s3 = 1/3*np.sin(2*np.pi*t*3*freq)

qq = y + s3


sd.play(qq, sr)
plot_fft(qq)

# %% 
def make_square( freq=440 , amp=0.5 , phase=0.0 , dur_secs=0.5 , sr=44100 ):
    t = np.arange(dur_secs*sr)/sr
    s = np.sin( 2*np.pi*freq*t )
    i = 3
    freq_harmonics = freq*i
    while freq_harmonics <= sr/2:
        s += (1/i)*np.sin( 2*np.pi*freq_harmonics*t )
        i += 2
        freq_harmonics = freq*i
    return amp*s

y = make_square(freq=2)

plt.plot(y)

