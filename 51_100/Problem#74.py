import math

def digitFactorialSum(n):
    return sum([math.factorial(int(x)) for x in str(n)])

def repeatedLength(n):
    repeatedList = []
    while n not in repeatedList:
        repeatedList.append(n)
        n = digitFactorialSum(n)
    return len(repeatedList)

if __name__ == "__main__":
    cnt = 0
    for i in range(1, 1000000):
        if repeatedLength(i) == 60:
            cnt += 1
    print cnt
