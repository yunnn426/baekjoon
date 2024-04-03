import sys, copy
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
ice = [[] for _ in range(n)]
for i in range(n):
    arr = list(map(int, input().split()))
    ice[i] = arr
tempice = copy.deepcopy(ice)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

############################################################
def melt():
    global ice, tempice
    for i in range(n):
        for j in range(m):
            if ice[i][j] <= 0: 
                continue

            # 사방의 바다 찾기
            cnt = 0
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                if nx < 0 or nx >= n or ny < 0 or ny >= m:
                    continue
                if ice[nx][ny] <= 0:
                    cnt += 1
            
            # 녹이기
            tempice[i][j] -= cnt
            if tempice[i][j] < 0:
                tempice[i][j] = 0
    ice = copy.deepcopy(tempice)

def bfs(visit, i, j):
    q = deque()
    visit[i][j] = 1
    q.append((i, j))
    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if visit[nx][ny] != 0:
                continue
            if ice[nx][ny] <= 0:
                continue
            
            visit[nx][ny] = 1
            q.append((nx, ny))

# 분리된 빙산 찾기
def findGlacier(visit):
    iceberg = 0
    for i in range(n):
        for j in range(m):
            if visit[i][j] != 0:
                continue
            if ice[i][j] <= 0:
                continue
            iceberg += 1
            visit[i][j] = 1
            bfs(visit, i, j)
    return iceberg
############################################################

# main

visited = [[0 for _ in range(m)] for _ in range(n)]
init = findGlacier(visited)
time = 0
while True:
    visited = [[0 for _ in range(m)] for _ in range(n)]
    time += 1
    melt()
    now = findGlacier(visited)
    if init < now: # 분리
        print(time)
        break
    elif now == 0: # 다 녹을 때까지 분리 x
        print(0)
        break
