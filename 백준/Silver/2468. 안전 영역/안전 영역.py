import sys
from collections import deque

n = int(sys.stdin.readline())
area = []
visited = [[0 for _ in range(n)] for _ in range(n)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
answer = 0

# bfs
def search(a, b, height): 
    q = deque()
    q.append([a, b])

    while len(q) != 0:
        x, y = q[0][0], q[0][1]
        q.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= n or nx < 0 or ny >= n or ny < 0: # out of range
                continue
            if visited[nx][ny] != 0: # 이미 방문
                continue
            if area[nx][ny] <= height: # 비에 잠김
                continue
            visited[nx][ny] = 1
            q.append([nx, ny])

#main
for _ in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    area.append(arr)

for i in range(101): # 비의 높이
    land = 0 #init
    visited = [[0 for _ in range(n)] for _ in range(n)]

    for x in range(n):
        for y in range(n):
            if area[x][y] <= i: # 비에 잠김
                continue
            if visited[x][y] != 0: # 이미 다른 지역에 소속된 경우
                continue
            land += 1
            visited[x][y] = 1
            search(x, y, i)
    
    if land == 0: # 비가 너무 많이 와서 땅이 없음
        break

    answer = max(answer, land)

print(answer)