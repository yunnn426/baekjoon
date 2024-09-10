import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
dp = [1 for _ in range(n)]

for i in range(1, n):
    dp[i] = 1
    for j in range(0, i):
        if a[i] > a[j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))