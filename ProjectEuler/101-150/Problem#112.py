def isBouncyNumber(n):
    x = [int(i) for i in str(n)]
    return x != sorted(x) and x != sorted(x, reverse=True)

def bouncyNumberProportion(n):
    x = [i for i in range(100, n+1) if isBouncyNumber(i)]
    return (len(x) + 0.0) / n

if __name__ == "__main__":
    cnt = 0;
    n = 99;
    while (cnt + 0.0) / n < 0.99:
        n += 1
        if isBouncyNumber(n):
            cnt += 1;
    print n, 0.99
