import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
a = sorted(a)

answer = 0
for i in range(n):
    start = 0
    end = n - 1

    while start < end:
        sum = a[start] + a[end]
        
        if end == i or sum > a[i]:
            end -= 1
        elif start == i or sum < a[i]:
            start += 1
        else:
            answer += 1
            break
            
print(answer)
