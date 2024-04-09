import sys
input = sys.stdin.readline

n = int(input())
cost = []
for i in range(n):
    r, g, b = list(map(int, input().split()))
    cost.append((r, g, b))

dp = [[0 for _ in range(n + 1)] for _ in range(3)]
for h in range(1, n + 1): # 1~n번 집
    for c in range(3): # R, G, B
        if h == 1:
            dp[c][h] = cost[0][c]
            continue

        if c == 0: # R
            # 이전 집을 B or G로 칠했을 때 최소값 가져옴
            dp[c][h] = min(dp[1][h - 1], dp[2][h - 1]) + cost[h - 1][c]
        
        elif c == 1: # G
            dp[c][h] = min(dp[0][h - 1], dp[2][h - 1]) + cost[h - 1][c]

        else:
            dp[c][h] = min(dp[0][h - 1], dp[1][h - 1]) + cost[h - 1][c]

# n번째 집을 칠하는 최소값
print(min(dp[0][n], dp[1][n], dp[2][n]))