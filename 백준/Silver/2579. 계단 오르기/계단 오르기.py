import sys
input = sys.stdin.readline

n = int(input())
stair = []
stair.append(0)
for _ in range(n):
    s = int(input())
    stair.append(s)

dp = [0 for _ in range(n + 1)]

for i in range(1, n + 1):
    if i == 1:
        dp[1] = stair[1]
    elif i == 2:
        dp[2] = dp[1] + stair[2]
    elif i == 3:
        dp[3] = max(stair[1] + stair[3], stair[2] + stair[3])
    else:
        # i번째 계단의 최대 점수
        # = 
        # i-2번째 계단까지의 최대 점수 + i번째 계단의 점수
        # i번째 계단의 점수 + i-1번째 계단의 점수 + i-3번째 계단까지의 점수 (연달아 세개 못올라가니까)
        # 중 큰 값
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i])

print(dp[n])