import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    coin = list(map(int, input().split()))
    m = int(input())

    dp = [0 for _ in range(m + 1)]
    dp[0] = 1
    for i in range(n):
        for j in range(1, m + 1):
            if j >= coin[i]:
                dp[j] += dp[j - coin[i]]
    
    print(dp[m])
