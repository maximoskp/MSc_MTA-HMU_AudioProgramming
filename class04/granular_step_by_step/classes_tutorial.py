#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov  7 18:57:33 2022

@author: max
"""

# make a basic class or Human
class Human:
    # Κάθε φορά που δημιουργούμε ένα αντικείμενο της κλάσης,
    # καλείται η συνάρτηση "__init__()". Αυτή η συνάρτηση 
    # ονομάζεται "constructor" και είναι η συνάρτηση που
    # καλείται όταν αρχικοποιούμε ένα αντικείμενο με το όνομα
    # της κλάσης. Πχ
    # h1 = Human(24)
    # καλεί τον constructor με όρισμα το 24.
    # Το "self" δίνεται πάντα σαν πρώτο όρισμα οποιασδήποτε
    # συνάρτησης της κλάσης. Το όρισμα αυτό όμως, δεν δίνεται
    # κατά την κλήση της συνάρτησης - πρέπει να αγνοείται, γιατί
    # η python θεωρεί αυτόματα πως το αντικείμενο που καλέι την
    # συνάρτησή του, είναι και το πρώτο όρισμα.
    def __init__(self, age_in, gender_in='F', name_in=None):
        self.age = age_in
        self.gender = gender_in
        self.name = name_in
        self.check_if_adult()
    # end __init__

    def check_if_adult(self):
        self.is_adult = False
        if self.age >= 18:
            self.is_adult = True
    # end check_if_adult

    def print_info(self):
        print('age:         ', self.age)
        print('gender:      ', self.gender)
        print('name:        ', self.name)
        print('is_adult:    ', self.is_adult)
# end Human

# %% 

h1 = Human(24) # το self παραλείπεται επειδή εννοείται
print('----------------------------')
h1.print_info() # η συνάρτηση αυτή δεν έχει "φανερό όρισμα", αλλά έχει
# κρυφό όρισμα το αντικείμενο που την καλεί - δηλ h1.

h2 = Human(12, 'M', 'Max')
print('----------------------------')
h2.print_info()

# %% 

# make a new class for Athlete that *inherits* from the class Human
# which makes sense, since athletes are humans
class Athlete(Human):
    def __init__(self, age, height=None, weight=None, gender='F', name=None):
        # Καλούμε τον constructor της κλάσης-μαμάς.
        super().__init__(age, gender=gender, name=name)
        # Θα μπορούσαμε απλά να βάλουμε
        # self.age = age
        # self.gender = gender
        # self.name = name
        # αλλά θα έπρεπε να ξανατρέξουμε τη συνάρτηση αναγνώρισης για το αν
        # είναι ενήλικη/ος.
        # Γιατί δεν το κάνουμε;
        # Επειδή η δύναμη της κληρονομικότητας είναι ότι αν αλλάξει κάτι
        # στον constructor της μαμάς-κλάσης, Human, η αλλαγή θα περάσει 
        # αυτόματα και στον παιδί-κλάση, Athlete.
        self.height = height
        self.weight = weight
        self.compute_bmi()
    # end __init__

    def compute_bmi(self):
        if self.height is None or self.weight is None:
            self.bmi = None
            self.bmi_category = None
        else:
            self.bmi = self.weight/(self.height**2)
            self.bmi_category = 'healthy'
            if self.bmi >= 25:
                self.bmi_category = 'overweight'
            elif self.bmi < 18.5:
                self.bmi_category = 'underweight'
    # end compute_bmi

    def print_info(self):
        super().print_info()
        print('height:      ', self.height)
        print('weight:      ', self.weight)
        print('bmi:         ', self.bmi)
        print('bmi cat.:    ', self.bmi_category)
# end class Athlete

# %%