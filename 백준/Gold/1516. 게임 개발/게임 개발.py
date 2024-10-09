from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
cost = [0 for _ in range(n + 1)]
build = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]

# input
for i in range(1, n + 1):
    lst = list(map(int, input().split()))[:-1]
    cost[i] = lst[0]
    for j in lst[1:]:
        build[j].append(i) # i -> j로 연결
        indegree[i] += 1

q = deque()
answer = [0 for _ in range(n + 1)]
# 깊이가 적은 것부터 차례대로 계산하기 위해
for i in range(1, n + 1):
    # 차수 0인 것 큐에 추가
    if indegree[i] == 0:
        q.append(i)
        answer[i] = cost[i]

while q:
    b = q.popleft()

    for i in build[b]:
        indegree[i] -= 1 # 이미 계산한 단계 제외
        answer[i] = max(answer[i], answer[b] + cost[i])
    
        if indegree[i] == 0:
            q.append(i)

print(*answer[1:], sep="\n")