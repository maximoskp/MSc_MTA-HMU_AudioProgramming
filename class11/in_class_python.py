#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan 10 18:50:56 2022

@author: max
"""

import numpy as np

x = np.array([[1,2,3,4], [5,6,7,8]])

print(x.shape[1])

y = x.T

# %% 

import matplotlib.pyplot as plt

# let's construct a curve that defines grain speed at each given time/sample
# let's assume that we have a composition with 5 seconds duration
dur_sec = 5
sample_rate = 44100
total_composition_samples = dur_sec*sample_rate

# speed curve construction part-wise
# first part is 1 second long, from speed 1 to speed 2
speed_part_1 = np.linspace(1, 2, 44100)
# second part is 3 secs long (from sec 2 to sec 4), from speed 2 to speed 1.5
speed_part_2 = np.linspace(2, 1.5, 3*44100)
# third part, the final second, from 1.5 to some large value
speed_part_3 = 1.5*np.exp( np.linspace(0, 2, 44100) )
# concatenate all three parts in one speed curve
speed_curve = np.hstack( ( speed_part_1, speed_part_2, speed_part_3 ) )

plt.plot(speed_curve)

# %% 

# block size: 2048
# how many blocks to keep: 1000
# we will end up with a matrix of size
x = np.random.rand(2048, 1000)
# we need to make a continuous waveform out the above
y = np.flip( x.T, axis=0 ).reshape( 1,x.size )
# to test the above, check with:
# x = np.array([[5,6,7,8],[1,2,3,4]]).T



