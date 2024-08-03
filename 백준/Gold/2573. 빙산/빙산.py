from collections import deque
import copy
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
glacier = [list(map(int, input().split())) for _ in range(n)]

answer = 0
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(i, j, visited):
    q = deque()
    q.append((i, j))
    visited[i][j] = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < n or not 0 <= ny < m:
                continue
            if visited[nx][ny] != 0 or glacier[nx][ny] <= 0:
                continue
            
            q.append((nx, ny))   
            visited[nx][ny] = 1

def melt(glacier):
    tmp_map = copy.deepcopy(glacier)

    for x in range(n):
        for y in range(m):
            if glacier[x][y] <= 0:
                continue
            
            # 인접한 바다의 수만큼 빙산이 녹는다.
            adj0 = 0
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if not 0 <= nx < n or not 0 <= ny < m:
                    continue
                
                if glacier[nx][ny] <= 0:
                    adj0 += 1

            tmp_map[x][y] = max(0, glacier[x][y] - adj0)

    return tmp_map

while True:
    answer += 1
    glacier = melt(glacier)

    visited = [[0 for _ in range(m)] for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(m):
            if visited[i][j] != 0 or glacier[i][j] <= 0:
                continue
            
            cnt += 1
            bfs(i, j, visited)
    
    # 빙산 분리됨
    if cnt > 1:
        break

    # 분리되지 않는 빙산
    if cnt == 0:
        answer = 0
        break

print(answer)