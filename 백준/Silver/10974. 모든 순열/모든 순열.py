import sys
input = sys.stdin.readline

n = int(input())

def dfs(arr, visited):
    if len(arr) == n:
        print(*arr)
        return
    
    for i in range(1, n + 1):
        if visited[i] != 0:
            continue
        
        visited[i] = 1
        dfs(arr + [i], visited)
        visited[i] = 0

dfs([], [0 for _ in range(n + 1)])