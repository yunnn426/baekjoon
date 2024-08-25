import sys
input = sys.stdin.readline

n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]
cnt = [0, 0, 0]

def dfs(x, y, width):
    global cnt
    idx = paper[x][y] # 종이의 모든 칸에 idx가 저장되어 있어야 한다.

    cut = False
    for i in range(x, x + width):
        for j in range(y, y + width):
            if paper[i][j] != idx:
                cut = True

    # 종이의 한 변은 항상 3의 제곱수이므로
    # 한 종이를 9개로 나누려면 한 변은 현재 width // 3이 된다.
    if cut:
        for i in range(x, x + width, width // 3):
            for j in range(y, y + width, width // 3):
                dfs(i, j, width // 3)
    else:
        if idx == -1:
            cnt[0] += 1
        elif idx == 0:
            cnt[1] += 1
        else:
            cnt[2] += 1

dfs(0, 0, n)
print(*cnt, sep="\n")
