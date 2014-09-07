import math

def periodOfdouble(x):
    """
    given x, express sqrt(x) using continued fraction, then return the
    period of sqrt(x)

    For example:
    x = 3
    sqrt(3) = [1;(1,2)]
    then return (1,2).length, which is 2

    There is a clear algorithm to solve this problem with iterative 
    method called Babylonian_method (wikipedia), I just implement it
    with Python.

    Good luck
    """
    ans = []
    sqrtx = math.floor(math.sqrt(x))
    m = 0
    d = 1
    a = int(math.floor(math.sqrt(x)))
    while (m,d,a) not in ans:
        ans.append((m,d,a))
        m = int(d * a - m)
        if d != 0:
            d = int((x - m**2) / d)
        else:
            return 0

        if d != 0:
            a = int(math.floor((sqrtx + m)/d))
        else:
            return 0
        #print(m, d, a)

    return len(ans) - 1

if __name__ == "__main__":
    periods = [periodOfdouble(i) for i in range(2, 10001)]
    print(len([j for j in periods if j % 2 == 1]))
