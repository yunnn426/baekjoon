import sys
n = int(sys.stdin.readline())
lst = []
for _ in range(n):
    num = int(sys.stdin.readline())
    lst.append(num)

lst.sort()

for i in lst:
    print(i)