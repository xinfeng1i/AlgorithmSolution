import math

def isPrime(n):
    mid = int(math.sqrt(n))
    for i in range(2, mid+1):
        if n % i == 0:
            return False
    return True

def isUniqueNumber(n):
    l = [int(x) for x in str(n)]
    return len(l) == len(set(l))

def isPermutations(x, y):
    s1 = set([int(i) for i in str(x)])
    s2 = set([int(j) for j in str(y)])
    return s1 == s2

if __name__ == "__main__":
    primes = [n for n in range(1000, 10000) if isPrime(n)]
    uniquePrimes = [x for x in primes if isUniqueNumber(x)]
    for x in primes:
        curArray = [y for y in primes if isPermutations(x, y)]
        curLength = len(curArray)
        if curLength >= 3:
            for i in range(0, curLength):
                for j in range(i + 1, curLength):
                    for k in range(j + 1, curLength):
                        if curArray[j] * 2 == curArray[i] + curArray[k]:
                            print curArray[i], curArray[j], curArray[k]
    print "END"

# only require permutations, but not unique digits
# make sure to understand the problem correctly.
