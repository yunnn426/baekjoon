import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
maze = [[] for _ in range(n)]
visited = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    string = input().strip()
    for j in range(n):
        maze[i].append(int(string[j]))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
answer = 1e8
q = deque()
visited[0][0] = 1
q.append((0, 0, 0)) # x, y, 바꾼 검은 방의 수

while q:
    x, y, cnt = q.popleft()

    # 목적지 도착하면 바꾼 검은 방의 수가 작은게 답
    if x == n - 1 and y == n - 1:
        answer = min(answer, cnt)

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        # 범위 체크
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        # 방문 체크
        if visited[nx][ny] != 0:
            continue
        
        visited[nx][ny] = 1
        # 1이면 큐의 앞에 추가해서 먼저 탐색
        if maze[nx][ny] == 1:
            q.appendleft((nx, ny, cnt))
        # 0이면 하얀 방으로 바꾸고 큐의 뒤에 추가
        else:
            q.append((nx, ny, cnt + 1))

print(answer)