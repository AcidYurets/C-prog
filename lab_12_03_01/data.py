from random import *


f = open("data.txt", "w")

for i in range(1500):
    f.write(str(randint(-1000,1000)) + "\n")
f.close()
        
    
