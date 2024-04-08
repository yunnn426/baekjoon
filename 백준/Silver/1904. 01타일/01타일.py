import sys
input = sys.stdin.readline

# 1개
# 1

# 2개
# 00, 11
 
# 3개
# 001, 100, 111

# 4개
# 0000, 1100, 0011, 1001, 1111

n = int(input())
dp = [0 for _ in range(n + 10)]
dp[1] = 1
dp[2] = 2
for i in range(3, n + 1):
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746

print(dp[n])