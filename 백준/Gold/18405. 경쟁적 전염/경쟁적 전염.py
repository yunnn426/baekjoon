# 경쟁적 전염
import sys
input = sys.stdin.readline

# input
n, k = map(int, input().split())
lab = [[] for _ in range(n)]
for i in range(n):
    arr = list(map(int, input().split()))
    lab[i] = arr
s, tgtx, tgty = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
def infect(visited, x, y, virus):
    global lab
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        if lab[nx][ny] != 0:
            continue
        if visited[nx][ny] != 0:
            continue

        visited[nx][ny] = 1
        lab[nx][ny] = virus

time = 0
while True:
    if time == s:
        break
    time += 1

    # 이미 알고싶은 곳이 전염이 완료되면 종료
    if lab[tgtx - 1][tgty - 1] != 0:
        break

    ## 전염
    visited = [[0 for _ in range(n)] for _ in range(n)]
    # 1~k 전염
    for t in range(1, k + 1):
        for x in range(n):
            for y in range(n):
                if visited[x][y] != 0:
                    continue
                
                if lab[x][y] == t:
                    visited[x][y] = 1
                    infect(visited, x, y, t)

print(lab[tgtx - 1][tgty - 1])