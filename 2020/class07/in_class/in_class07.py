#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov 29 20:23:38 2021

@author: max
"""

import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd

x = np.array([1,2,3,4,5,6,7])
y = x%5

# %% 

x = np.arange(44100)
y = x%5

sd.play(y/5 , 44100)

# plt.plot(y)


# %%

x = np.arange(44100)
y = x%100 - 3*x%77 - 7*x%22

plt.plot(y, '.-')
sd.play(y/100 , 44100)
















