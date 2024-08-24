from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dist = [[1e9 for _ in range(n + 1)] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    dist[a][b] = 1
    dist[b][a] = 1

# 모든 건물 사이 거리 구하기
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            dist[i][j] = 0
            continue
        
        for k in range(1, n + 1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

answer = 1e9
a = 0
b = 0
# i, j에 치킨집
for i in range(1, n + 1):
    for j in range(1, n + 1):
        sum = 0

        for k in range(1, n + 1):
            sum += min(dist[i][k], dist[j][k])
        
        if sum < answer:
            a = i
            b = j
            answer = sum
    
print(a, b, 2 * answer)
            