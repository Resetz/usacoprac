import random

#global variables here (variables to be accessed by all of your code)
hints = dict()
hints["LOS ANGELES"] = ["This city is a major city in North America.", "This city is known for the 'Hollywood Walk Of Fame'."]

MAXTRIES = 3


#functions go here
def valid(s: str):
  good = True
  for x in s.split(" "):
    if (not x.isalpha()):
      good = False
      break
  return good


def maincode():
  city = "LOS ANGELES" # change this in your code between here and the tries loop
  tries = 3
  while (tries > 0):
    
  
    guess = input("Enter city -> ").upper()
    while (not valid(guess)):
      guess = input("That city is not valid, enter again -> ").upper()
  
    #guess is valid here
    if (guess == city):
      # you win!
      break
    else:
      tries = tries - 1
      print("You have", tries, end = " ")
      if (tries == 1):
        print("try left.")
      else:
        print("tries left.")
      if (tries != 0):
        print(hints[city][MAXTRIES-tries-1])

    print()

maincode()