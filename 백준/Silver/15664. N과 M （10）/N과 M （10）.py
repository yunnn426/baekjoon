from collections import Counter
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
numbers = sorted(numbers)

seq = set()
visited = [0 for _ in range(n)]

def dfs(cnt, idx, arr):
    if cnt == m:
        seq.add(tuple(arr))
        return

    for i in range(idx + 1, n):
        if visited[i] != 0:
            continue
        visited[i] = 1
        dfs(cnt + 1, i, arr + [numbers[i]])
        visited[i] = 0

# main
for i in range(n):
    visited[i] = 1
    dfs(1, i, [numbers[i]])
    visited[i] = 0

# answer
seq = sorted(seq)
for i in seq:
    for x in i:
        print(x, end=" ")
    print()