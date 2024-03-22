# fast input
import sys

n, m = map(int, sys.stdin.readline().split())
arr = []

# make array
for i in range(1, n + 1):
    arr.append(i)

# reverse
for i in range(1, m + 1):
    a, b = map(int, sys.stdin.readline().split())

    n1arr = arr[0:a - 1]
    rarr = arr[a-1:b]
    rarr.reverse()
    n2arr = arr[b:]
    arr = n1arr + rarr + n2arr

for i in arr:
    print(i, end = " ")