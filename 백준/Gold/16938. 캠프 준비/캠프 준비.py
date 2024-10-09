import sys
input = sys.stdin.readline

n, l, r, x = map(int, input().split())
a = list(map(int, input().split()))
answer = 0

def dfs(arr, idx):
    if len(arr) >= 2:
        if l <= sum(arr) <= r and max(arr) - min(arr) >= x:
            global answer
            answer += 1

    for i in range(idx, n):
        dfs(arr + [a[i]], i + 1)

for i in range(n):
    dfs([a[i]], i + 1)

print(answer)