import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coin = [int(input()) for _ in range(n)]

dp = [0 for _ in range(k + 1)]
dp[0] = 1

# c 동전까지만 써서
for c in coin:
    # c ~ k원을 만들 수 있는 경우의 수
    for i in range(c, k + 1):
        dp[i] += dp[i - c]

print(dp[-1])