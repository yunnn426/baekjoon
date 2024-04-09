import sys
input = sys.stdin.readline

n = int(input())
dp = [0 for _ in range(n + 1)]

for i in range(1, n + 1):
    # dp init
    if i == 1:
        dp[1] = 0
        continue
    if i == 2:
        dp[2] = 1
        continue
    if i == 3:
        dp[3] = 1
        continue

    if i % 6 == 0:
        dp[i] = min(dp[i - 1] + 1, dp[i // 3] + 1, dp[i // 2] + 1)
    elif i % 3 == 0:
        dp[i] = min(dp[i - 1] + 1, dp[i // 3] + 1)
    elif i % 2 == 0:
        dp[i] = min(dp[i - 1] + 1, dp[i // 2] + 1)
    else:
        dp[i] = dp[i - 1] + 1

print(dp[n])