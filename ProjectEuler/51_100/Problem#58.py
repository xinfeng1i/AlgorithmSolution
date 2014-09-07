import math
def isPrime(n):
    mid = int(math.sqrt(n))
    for i in range(2, mid + 1):
        if n % i == 0:
            return False
    return True


if __name__ == "__main__":
    
    sideLength = 3
    n = 5
    nPrimes = 3
    ratio = (nPrimes + 0.0) / n
    while ratio >= 0.10:
        sideLength += 2

        rightBottom = sideLength**2
        n_list = [rightBottom, rightBottom - (sideLength- 1), rightBottom - 2 * (sideLength - 1), rightBottom - 3 * (sideLength - 1)]
        nPrimes_list = [x for x in n_list if isPrime(x)]

        n += 4
        nPrimes += len(nPrimes_list)
        ratio = (nPrimes + 0.0) / n

    print("side length: ", sideLength)
    print("right bottom: ", sideLength**2)
    print("primes ratio: ", ratio)
