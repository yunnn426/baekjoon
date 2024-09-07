import sys
input = sys.stdin.readline

n, p, q = map(int, input().split())

dp = {}
dp[0] = 1

for i in range(1, 1000000):
    dp[i] = dp[i // p] + dp[i // q]

def dfs(i):
    if i in dp:
        return dp[i]
    return dfs(i // p) + dfs(i // q)

print(dfs(n))