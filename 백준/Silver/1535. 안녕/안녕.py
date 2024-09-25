import sys
input = sys.stdin.readline

n = int(input())
hp = list(map(int, input().split()))
happy = list(map(int, input().split()))

dp = [[0 for _ in range(n)] for _ in range(100)]

for w in range(100):
    for k in range(n):
        if k == 0:
            if w >= hp[k]:
                dp[w][k] = happy[k]
            continue

        if w >= hp[k]: # 인사를 하거나 안하거나
            dp[w][k] = max(dp[w][k - 1], dp[w - hp[k]][k - 1] + happy[k])
        else:
            dp[w][k] = dp[w][k - 1]

print(dp[-1][-1])