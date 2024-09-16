from collections import deque
from copy import deepcopy
import sys
input = sys.stdin.readline

h, w = map(int, input().split())
board = [[0 for _ in range(w)] for _ in range(h)]
before = 0
for i in range(h):
    row = list(map(int, input().split()))
    for j in range(w):
        if row[j] == 1:
            board[i][j] = 1
            before += 1
        
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
tmp_board = deepcopy(board)

def bfs():
    q = deque()
    q.append((0, 0)) # 0,0에서 접근 가능한 치즈는 녹는 치즈
    visited = [[0 for _ in range(w)] for _ in range(h)]
    visited[0][0] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < h or not 0 <= ny < w:
                continue
            if visited[nx][ny] != 0:
                continue
            if board[nx][ny] == 1: # 치즈 녹음
                tmp_board[nx][ny] = 0
                continue
            
            q.append((nx, ny))
            visited[nx][ny] = 1

def check():
    cheese = 0
    for i in range(h):
        for j in range(w):
            if tmp_board[i][j] == 1:
                cheese += 1

    return cheese

time = 0
while True:
    bfs()

    time += 1
    cheese = check()
    if cheese != 0:
        before = cheese
        board = deepcopy(tmp_board)
        continue

    print(time, before, sep="\n")
    break