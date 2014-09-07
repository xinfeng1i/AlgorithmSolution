import math

def digitSum(n):
    return sum([int(x) for x in str(n)])

def isDigitPowerNumber(n):
    b = digitSum(n)
    i = 1
    while b**i < n:
        i += 1
    
    return b**i == n

if __name__ == "__main__":
    ans = []
    x = 11
    while True:
        if len(ans) >= 31:
            break
        # print x
        if digitSum(x) != 1 and isDigitPowerNumber(x):
            ans.append(x)
            print "append %d", x

        x += 1
    print ans


