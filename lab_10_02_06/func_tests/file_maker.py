for i in range (1, 8):
    a = "pos"+str(i)+".txt"
    print(a)
    my_file = open(a, "w")
    my_file.close()

for i in range (1, 4):
    a = "neg"+str(i)+".txt"
    print(a)
    my_file = open(a, "w")
    my_file.close()
