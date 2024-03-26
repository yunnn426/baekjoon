import sys

n = int(sys.stdin.readline())
arr1 = list(map(int, sys.stdin.readline().split()))

dict = {}
for i in arr1:
    dict[i] = 1

m = int(sys.stdin.readline())
arr2 = list(map(int, sys.stdin.readline().split()))

for i in arr2:
    if i in dict:
        print(1)
    else:
        print(0)