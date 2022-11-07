#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov  7 18:42:06 2022

@author: max
"""

# αν δεν είναι βιβλιοθήκη της python και είναι βιβλιοθήκη από 
# δικό μας αρχείο,
# πρέπει να είναι στον ίδιο φάκελο με το αρχείο που το καλεί
import audio_utils as au

s = au.make_sine()

# %% 

def just_print():
    print('hello!')
# end just_print

print('before hello')
just_print()


# %% 

t = 6
y = 5

def double_input(x):
    y = 2*x
    print('t = ', t)
    return y
# end double_input

print('y = ', y)

a = double_input(5)