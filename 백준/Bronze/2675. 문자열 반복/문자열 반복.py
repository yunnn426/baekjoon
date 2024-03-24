import sys
t = int(sys.stdin.readline())
for _ in range(t):
    r, s = map(str, sys.stdin.readline().split())
    for i in range(len(s)):
        for j in range(int(r)):
            print(s[i], end="")
    print()