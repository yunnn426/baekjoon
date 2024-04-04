# 단지번호붙이기
import sys
from collections import deque
input = sys.stdin.readline

# input
n = int(input())
house = [[] for _ in range(n)]
for i in range(n):
    string = input().strip()
    for j in range(n):
        house[i].append(int(string[j]))

visited = [[0 for _ in range(n)] for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
ans_arr = []
ans = 0

for i in range(n):
    for j in range(n):
        if visited[i][j] != 0:
            continue
        if house[i][j] == 0:
            continue
        
        # bfs
        ans += 1 # 새로운 단지 찾음
        cnt = 0 # 단지 내 집의 수 카운트
        q = deque()
        visited[i][j] = 1
        q.append((i, j))
        while q:
            x, y = q.popleft()
            cnt += 1

            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if nx < 0 or nx >= n or ny < 0 or ny >= n: # 범위체크
                    continue
                if visited[nx][ny] != 0:
                    continue
                if house[nx][ny] == 0:
                    continue
                
                visited[nx][ny] = 1
                q.append((nx, ny))
        ans_arr.append(cnt)

print(ans)
ans_arr.sort()
for i in ans_arr:
    print(i)