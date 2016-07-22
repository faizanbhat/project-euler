"""
Euler 22
What is the total of all the name scores in the given file?
> ./data/p022_names.txt

"""
import timeit

def name_score(name,ind):
    sc = 0 
    for char in name: 
        sc = sc + (ord(char) - ord("`"))
    sc = sc * (ind+1)
    return sc

start_time = timeit.default_timer()
f = open("./data/p022_names.txt")
line = f.readlines() #read
names = line[0].replace("\"", "").lower().split(",")
names.sort()
total = 0
for name in names:
    total = total + name_score(name, names.index(name))
print total
print "Time: " + str(timeit.default_timer() - start_time)