from random import *
inp = open("data.txt", 'w')



for i in range(1000):
    x = randint(1, 1000)
    inp.write(str(x) + " ")

inp.close()
