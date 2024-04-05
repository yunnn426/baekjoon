import sys
input = sys.stdin.readline

n, k = map(int, input().split())
item = []
for _ in range(n):
    w, v = map(int, input().split())
    item.append((w, v))

dp = [[0 for _ in range(k + 1)] for _ in range(n + 1)]
for i in range(n + 1):
    for j in range(k + 1):
        if i == 0 or j == 0:
            dp[i][j] == 0
            continue

        w, v = item[i - 1]
        if w <= j: # 현재 아이템의 무게가 현재 무게 제한보다 낮으면 
            # 현재 아이템을 넣지 않음 vs 가방을 필요한만큼 비우고 현재 아이템을 추가
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v)
        else:
            # 제한보다 무거우면 넣지 않음
            dp[i][j] = dp[i - 1][j]

print(dp[n][k])