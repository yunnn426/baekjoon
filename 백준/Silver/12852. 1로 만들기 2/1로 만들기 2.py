import sys
input = sys.stdin.readline

n = int(input())
dp = [0 for _ in range(n + 1)]
log = [1 for _ in range(n + 1)]

for i in range(1, n + 1):
    if i == 1:
        continue
    if i == 2:
        dp[i] = 1
        continue
    if i == 3:
        dp[i] = 1
        continue

    if i % 6 == 0:
        if dp[i // 2] < dp[i // 3]:
            if dp[i - 1] < dp[i // 2]:
                dp[i] = dp[i - 1] + 1
                log[i] = i - 1
            else: 
                dp[i] = dp[i // 2] + 1
                log[i] = i // 2
        else:
            if dp[i - 1] < dp[i // 3]:
                dp[i] = dp[i - 1] + 1
                log[i] = i - 1
            else:
                dp[i] = dp[i // 3] + 1
                log[i] = i // 3

    elif i % 3 == 0:
        if dp[i // 3] < dp[i - 1]:
            dp[i] = dp[i // 3] + 1
            log[i] = i // 3
        else:
            dp[i] = dp[i - 1] + 1
            log[i] = i - 1

    elif i % 2 == 0:
        if dp[i // 2] < dp[i - 1]:
            dp[i] = dp[i // 2] + 1
            log[i] = i // 2
        else:
            dp[i] = dp[i - 1] + 1
            log[i] = i - 1

    else:
        dp[i] = dp[i - 1] + 1
        log[i] = i - 1

print(dp[n])
while n >= 2:
    print(n, end=" ")
    n = log[n]
print(1)