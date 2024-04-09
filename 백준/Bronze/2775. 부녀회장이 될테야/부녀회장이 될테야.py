import sys
input = sys.stdin.readline

dp = [[0 for _ in range(15)] for _ in range(15)]
for i in range(15): # i: 층수
    for j in range(15): # j: 호수
        if j == 1:
            dp[i][j] = 1 # 1호에는 1명만 산다
            continue
        
        if i == 0:
            dp[i][j] = j # 0층 i호에는 i명이 산다
            continue

        # i층 j호에는 i-1층 1~j호까지의 사람이 산다
        # == 
        # i층 j-1호 사람 + i-1층 j호 사람
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        
t = int(input())
for _ in range(t):
    k = int(input())
    n = int(input())

    print(dp[k][n])