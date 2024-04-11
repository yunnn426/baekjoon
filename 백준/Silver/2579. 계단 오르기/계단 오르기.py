# 계단 오르기
import sys
input = sys.stdin.readline

n = int(input())
stair = [0]
for _ in range(n):
    s = int(input())
    stair.append(s)

dp = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    if i == 1:
        dp[i] = stair[1]
    elif i == 2:
        dp[i] = stair[1] + stair[2]
    elif i == 3:
        dp[i] = max(stair[1] + stair[3], stair[2] + stair[3])
    
    # 직전 계단을 밟거나 그 전 계단을 밟는 경우를 고려함
    else:
        # i-2까지 오른 후 i에 오르는 경우
        # i-3까지 오른 후 i-1에 오르고 i에 오르는 경우
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i])

print(dp[n])