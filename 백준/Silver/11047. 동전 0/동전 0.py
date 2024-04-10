import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coin = []
for _ in range(n):
    c = int(input())
    coin.append(c)

answer = 0
for i in range(len(coin) - 1, -1, -1):
    if k >= coin[i]:
        cnt = k // coin[i]
        k -= cnt * coin[i]
        answer += cnt

print(answer)