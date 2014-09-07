import sys

s = raw_input()
n = raw_input()
n = long(n)

cnt = 0
while cnt < n:
    line = sys.stdin.readline()
    cnt += 1
    str1 = line[0:1]
    str2 = line[3:-1]
    s = s.replace(str1, str2)

#print "s:" + s

ans = long(s)
ans = ans % 1000000007
print ans
