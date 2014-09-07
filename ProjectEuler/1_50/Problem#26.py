import numpy
import math

def repeatedDecimal(a, b):
    ans = []
    while True:

        while a < b:
            a *= 10
        #print ans

        # record all the numbers that have been numerator
        if a not in ans:
            ans.append(a)
        else:
            return len(ans) - ans.index(a)
        
        # a%b==0 means at some time, it can be divide evenly.
        # not a repeated decimal
        if a % b == 0:
            return 0
        else:
            a = a % b

if __name__ == "__main__":
    maxCycle = 0
    maxd = 0
    for d in range(2, 1000):
        cycle = repeatedDecimal(1, d)
        if cycle > maxCycle:
            maxCycle = cycle
            maxd = d
    print "max Cycle: ", maxCycle
    print "max d: ", maxd
