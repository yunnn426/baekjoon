n = int(input())
dp = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    if i == 1 or i == 2:
        dp[i] = 1
        continue
    dp[i] = dp[i - 2] + dp[i - 1]

print(dp[n])