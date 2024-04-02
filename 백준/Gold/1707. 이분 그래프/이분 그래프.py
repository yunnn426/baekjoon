import sys
sys.setrecursionlimit(10**6)
k = int(sys.stdin.readline())
result = True

def dfs(x, before):
    for i in graph[x]:
        # 컬러 먼저 보기
        if color[i] == -1: # 컬러 부여 전
            color[i] = abs(before - 1)
        elif color[i] == before: # 같은 컬러 -> 같은 컬러 dfs : NO
           global result
           result = False

        # 방문 확인
        if visited[i] != 0:
            continue
        visited[i] = 1
        dfs(i, color[i])


for _ in range(k):
    v, e = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(v + 1)]
    color = [-1 for _ in range(v + 1)] # 0은 red, 1는 blue
    visited = [0 for _ in range(v + 1)]
    result = True

    for _ in range(e):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)

    for i in range(1, v + 1):
        if visited[i] != 0:
            continue
        visited[i] = 1
        dfs(i, 0)
    
    if result: print("YES")
    else: print("NO")