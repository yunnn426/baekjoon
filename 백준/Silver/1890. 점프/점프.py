# 점프
import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
game = []
for _ in range(n):
    arr = list(map(int, input().split()))
    game.append(arr)

dx = [1, 0]
dy = [0, 1]

######
# dp #
######
dp = [[0 for _ in range(n)] for _ in range(n)]
dp[0][0] = 1 # 시작점
for x in range(n):
    for y in range(n):
        if dp[x][y] == 0:
            continue
        if x == n - 1 and y == n - 1:
            break

        # 해당 지점에서 출발할 수 있는 경우
        # 갈 수 있는 다음 칸에 경로수 +1
        step = game[x][y]
        if step == 0:
            continue
        for i in range(2):
            nx = x + dx[i] * step
            ny = y + dy[i] * step

            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            
            dp[nx][ny] += dp[x][y]

print(dp[n - 1][n - 1])