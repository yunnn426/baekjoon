import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
answer = 0

def calc(arr):
    sum = 0
    for i in range(n - 1):
        sum += abs(arr[i] - arr[i + 1])
    
    return sum

# 가능한 모든 순열 만들기
def dfs(arr, visited):
    if len(arr) == n:
        global answer
        answer = max(answer, calc(arr))
        return
    
    for i in range(n):
        if visited[i] != 0:
            continue
        visited[i] = 1
        dfs(arr + [a[i]], visited)
        visited[i] = 0

dfs([], [0 for _ in range(n)])
print(answer)