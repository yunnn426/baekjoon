import sys
input = sys.stdin.readline

a = input().strip()
a = "_" + a
b = input().strip()
b = "-" + b
dp = [[0 for _ in range(len(b))] for _ in range(len(a))]

for i in range(1, len(a)):
    for j in range(1, len(b)):
        if i == 0 or j == 0:
            dp[i][j] = 0
            continue
        
        if a[i] == b[j]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

print(dp[-1][-1])        