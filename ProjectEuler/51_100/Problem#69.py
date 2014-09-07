def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def phi(n):
    return len([x for x in range(1, n) if gcd(x, n) == 1])

if __name__ == "__main__":
    maxRatio = 0.0
    maxN = 1
    for n in range(2, 1000001):
        if (n + 0.0) / phi(n) > maxRatio:
            maxRatio = (n + 0.0) / phi(n)
            maxN = n
    
    print "maxRatio:", maxRatio
    print "n: ", maxN

