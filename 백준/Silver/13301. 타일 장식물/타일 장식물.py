import sys
input = sys.stdin.readline

n = int(input())

# 둘레: 4, 6, 10, 16, 26, 42 ...
dp = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    if i == 1: 
        dp[i] = 4
        continue
    if i == 2: 
        dp[i] = 6
        continue

    dp[i] = dp[i - 1] + dp[i - 2]

print(dp[n])