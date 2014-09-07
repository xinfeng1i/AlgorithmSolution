import numpy

keys = []
with open("keylog.txt") as f:
    for line in f:
        for x in line.split():
            keys.append(int(x))

# Then I just do it by hand, observe, guess, check. :)
