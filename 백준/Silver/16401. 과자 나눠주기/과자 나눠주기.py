import sys
input = sys.stdin.readline

m, n = map(int, input().split())
length = list(map(int, input().split()))

def check(i):
    sum = 0
    for l in length:
        sum += (l // i)
    
    return sum

start = 1
end = 1000000000
answer = 0

while start <= end:
    mid = (start + end) // 2
    cnt = check(mid)

    if cnt < m:
        end = mid - 1
    else:
        answer = mid
        start = mid + 1

print(answer)