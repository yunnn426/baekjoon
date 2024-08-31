import sys
input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))
dp = [0 for _ in range(n)]

for i in range(n):
    before = 0 # 이전까지 최대값
    for j in range(0, i):
        if seq[j] < seq[i]:
            before = max(before, dp[j])
    
    dp[i] = before + 1

print(max(dp))