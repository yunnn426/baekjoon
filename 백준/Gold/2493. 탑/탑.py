import sys

n = int(input())
top = list(map(int, sys.stdin.readline().split()))
answer = [0 for _ in range(n)]
check = []
check.append([top[-1], n - 1]) # 높이-인덱스 저장

for i in range(n - 2, -1, -1):
    if check[-1][0] < top[i]: # 현재 스택에 있는 탑보다 높은 탑이 들어오면
        cnt = 0
        while check[-1][0] < top[i]:
            idx = check.pop()[1]
            answer[idx] = i + 1
            if len(check) == 0:
                break
        
    check.append([top[i], i])

for i in answer:
    print(i, end=" ")