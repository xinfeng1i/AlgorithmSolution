x = [a**b for a in range(2, 101) for b in range(2, 101)]
s = set(x)
ans = len(s)

print ans
