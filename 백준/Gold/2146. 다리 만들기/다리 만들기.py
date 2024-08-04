from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
world = [list(map(int, input().split())) for _ in range(n)]

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
land = set() # 육지 x - y - 섬 번호
q_land = deque()
visited = [[0 for _ in range(n)] for _ in range(n)]
idx = 0

def bfs(i, j, idx):
    q = deque()
    q.append((i, j))
    visited[i][j] = 1

    while q:
        x, y = q.popleft()
        land.add((x, y, idx))

        border = False # 섬 외곽만
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < n or not 0 <= ny < n:
                continue
            if world[nx][ny] == 0:
                border = True
            if visited[nx][ny] != 0 or world[nx][ny] == 0:
                continue

            q.append((nx, ny))
            visited[nx][ny] = 1
        
        if border:
           q_land.append((x, y, idx, 0))


# 각 섬들의 좌표 구하기
for i in range(n):
    for j in range(n):
        if visited[i][j] != 0 or world[i][j] == 0:
            continue

        bfs(i, j, idx)
        idx += 1

# 섬에서 다른 섬까지 최단거리 찾기
answer = 1e9
visit = [[[0 for _ in range(idx)] for _ in range(n)] for _ in range(n)]
while q_land:
    x, y, index, cost = q_land.popleft()

    # 이미 최단거리보다 값이 더 크면 확인 X
    if cost >= answer:
        continue

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if not 0 <= nx < n or not 0 <= ny < n:
            continue

        # 다른 섬에 도착
        for j in range(idx):
            if j == index:
                continue
            if (nx, ny, j) in land:
                answer = min(answer, cost)

        if visit[nx][ny][index] != 0 or world[nx][ny] == 1:
            continue
        
        q_land.append((nx, ny, index, cost + 1))
        visit[nx][ny][index] = 1

print(answer)