#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov  7 20:44:41 2022

@author: max
"""

# -*- coding: utf-8 -*-
"""
Created on Thu Dec  3 21:12:23 2020

@author: user
"""

import librosa
import audio_utils as au
import soundfile as sf
import sounddevice as sd
import numpy as np
import matplotlib.pyplot as plt

filename = 'audio_files/celloSampleStereo.wav'

y, sr = librosa.load(filename, sr=44100)

# example: random composition
# initialise composition of 10 secs
composition_duration = 10
sr = 44100
composition_samples = composition_duration*sr
c = np.zeros( ( composition_samples , 2 ) )
# let's place a number of notes randomly
n = 5000
for i in range( n ):
    # random note
    r = au.get_stereo_random_part( y , s=0 , e=70000 , d_min=1000 , d_max=5000 , pan=0.5 )
    # place note randomly within the composition
    tmp_idx = np.random.randint(composition_samples - 44100-22050)
    # apply random panning
    tmp_pan = np.random.random()
    c[ tmp_idx:(tmp_idx+r.shape[0]) , 0 ] += tmp_pan*r[:,0]
    c[ tmp_idx:(tmp_idx+r.shape[0]) , 1 ] += (1-tmp_pan)*r[:,0]

# normalize
c = c / np.max( np.abs( c ) )
sf.write('audio_files/random_cello_composition.wav', c, 44100, 'PCM_24')