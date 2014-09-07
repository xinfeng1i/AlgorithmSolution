import math

def ndigit(n):
    return len(str(n))

if __name__ == "__main__":
    ans = []
    for i in range(1, 100):
        for base in range(1, 10):
            power = i
            n = int(math.pow(base, i))
            if ndigit(n) == power:
                ans.append(n)
    print (ans)
    print (len(ans))
    print (ndigit(16807))
