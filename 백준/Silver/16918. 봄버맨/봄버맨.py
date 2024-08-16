from collections import deque
from copy import deepcopy
import sys
input = sys.stdin.readline

r, c, n = map(int, input().split())
# 반복: board -> bombs -> boom1 -> bombs -> boom2 -> bombs -> boom1 ...
board = [['' for _ in range(c)] for _ in range(r)] # 초기상태
boom1 = [['O' for _ in range(c)] for _ in range(r)] # 초기상태 상하좌우 제외하고 폭탄
boom2 = [['O' for _ in range(c)] for _ in range(r)] # boom1 상태에서 폭탄 터진 후
bombs = [['O' for _ in range(c)] for _ in range(r)] # 모든 칸 폭탄
q = deque()
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(r): 
    string = input()
    for j in range(c): 
        if string[j] == 'O':
           q.append((i, j)) 
        board[i][j] = string[j]


def bfs1():
    while q:
        x, y = q.popleft()
        boom1[x][y] = '.'

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < r or not 0 <= ny < c:
                continue
            
            boom1[nx][ny] = '.'

def bfs2():
    q = deque()
    for i in range(r):
        for j in range(c):
            if boom1[i][j] == 'O':
                q.append((i, j))

    while q:
        x, y = q.popleft()
        boom2[x][y] = '.'

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not 0 <= nx < r or not 0 <= ny < c:
                continue
        
            boom2[nx][ny] = '.'

def print_board(world):
    for i in range(r):
        for j in range(c):
            print(world[i][j], end='')
        print()

# boom1
bfs1()
# boom2
bfs2()

# 짝수일 때는 모든 칸 폭탄
if n % 2 == 0 and n != 0:
    print_board(bombs)
# 1초일 때는 초기상태
elif n == 1:
    print_board(board)
else:
    # -1 후 4의 배수이면 boom1에서 폭탄 터진 후
    if (n - 1) % 4 == 0:
        print_board(boom2)
    # 그 이외는 초기상태 상하좌우 제외하고 폭탄
    else:
        print_board(boom1)