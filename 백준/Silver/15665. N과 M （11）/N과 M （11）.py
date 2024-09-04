import sys
input = sys.stdin.readline
sys.setrecursionlimit = 1e9

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
answer = set()

def dfs(cnt, arr):
    if cnt == m:
        answer.add(tuple(arr))
        return
    
    for i in range(n):
        dfs(cnt + 1, arr + [numbers[i]])

dfs(0, [])

answer = sorted(answer)

for i in answer:
    for j in i:
        print(j, end=" ")
    print()