import sys
input = sys.stdin.readline

n = int(input())
liquid = list(map(int, input().split()))

answer = [1e10, -1, -1] # 특성값, 두 용액의 인덱스
start = 0
end = n - 1

while start < end:
    sum = liquid[start] + liquid[end]

    if abs(sum) < abs(answer[0]):
        answer = [sum, start, end]
    
    if sum > 0:
        end -= 1
    elif sum < 0:
        start += 1
    else:
        break

print(liquid[answer[1]], liquid[answer[2]])