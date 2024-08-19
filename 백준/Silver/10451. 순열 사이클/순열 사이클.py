import sys
input = sys.stdin.readline

tc = int(input())

def dfs(seq, visited, x):
    y = seq[x]

    if visited[y] == 0:
        visited[y] = 1
        dfs(seq, visited, y)


for t in range(tc):
    n = int(input())
    seq = [0] + list(map(int, input().split()))
    
    visited = [0 for _ in range(n + 1)]
    cycle = 0
    
    for i in range(1, n + 1):
        if visited[i] != 0:
            continue
        
        visited[i] = 1
        cycle += 1
        dfs(seq, visited, i)
    
    print(cycle)
