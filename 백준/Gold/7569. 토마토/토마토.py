import sys

import sys
from collections import deque

input = sys.stdin.readline
m, n, h = map(int, input().split())

box = [[] for _ in range(h)]
for H in range(h):
    for N in range(n):
        t = list(map(int, input().split()))
        box[H].append(t)

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]
visited = [[[0 for _ in range(m)] for _ in range(n)] for _ in range(h)]
q = deque()

# 초기: 익은 토마토 큐에 추가
for i in range(h):
    for j in range(n):
        for k in range(m):
            if visited[i][j][k] != 0:
                continue
            if box[i][j][k] == 1: 
                visited[i][j][k] = 1
                q.append((i, j, k, 0))

days = 0 # 모두 익는 데 걸리는 날
while q:
    x, y, z, cnt = q.popleft()
    days = max(cnt, days)

    for i in range(6):
        nx = x + dx[i]
        ny = y + dy[i]
        nz = z + dz[i]

        # 범위 체크
        if nx < 0 or nx >= h or ny < 0 or ny >= n or nz < 0 or nz >= m:
            continue
        # 방문 여부 체크
        if visited[nx][ny][nz] != 0:
            continue
        # 익지 않은 토마토만 익었다고 갱신
        if box[nx][ny][nz] == 0:
            box[nx][ny][nz] = 1
            visited[nx][ny][nz] = 1
            q.append((nx, ny, nz, cnt + 1))

# 토마토가 모두 익었는지 확인
def checkTomato():
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if box[i][j][k] == 0:
                    return False
    return True
                    
answer = checkTomato()
if answer: 
    if days == 0:
        print(0)
    else:
        print(days)
else: 
    print(-1)