import sys
input = sys.stdin.readline

n = int(input())
dp = [0 for _ in range(n + 10)]

dp[0] = -1
dp[1] = -1
dp[2] = -1
dp[3] = 1
dp[4] = -1
dp[5] = 1
dp[6] = 2
dp[7] = -1
dp[8] = 2
dp[9] = 3
dp[10] = 2
dp[11] = 3
dp[12] = 4
for i in range(13, n + 1):
    if i % 5 == 0:
        dp[i] = min(i // 5, dp[i - 3] + 1, dp[i - 5] + 1)
    elif i % 3 == 0:
        dp[i] = min(i // 3, dp[i - 3] + 1, dp[i - 5] + 1)
    else:
        dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1)

print(dp[n])