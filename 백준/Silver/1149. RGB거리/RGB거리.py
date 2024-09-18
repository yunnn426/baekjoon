import sys
input = sys.stdin.readline

n = int(input())
cost = [list(map(int, input().split())) for _ in range(n)]

dp = [[1e9 for _ in range(3)] for _ in range(n)]
for i in range(3):
    dp[0][i] = cost[0][i]

for i in range(1, n):
    for j in range(3):
        # 직전 집까지 칠하는 가장 저렴한 비용 구하기
        before = 1e9
        for k in range(3):
            if k == j: 
                continue
            before = min(before, dp[i - 1][k])
        
        # 위에서 구한 비용 + j번째 색으로 칠하는 비용
        dp[i][j] = cost[i][j] + before

print(min(dp[n - 1]))