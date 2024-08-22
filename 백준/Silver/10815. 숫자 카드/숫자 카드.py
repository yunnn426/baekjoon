import sys
input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))
seq = sorted(seq)
m = int(input())
num = list(map(int, input().split()))

def check(i):
    start = 0
    end = n - 1

    while start <= end:
        mid = (start + end) // 2

        if i > seq[mid]:
            start = mid + 1
        elif i < seq[mid]:
            end = mid - 1
        else:
            return True
    
    return False

for i in num:
    if check(i):
        print(1, end=" ")
    else:
        print(0, end=" ")