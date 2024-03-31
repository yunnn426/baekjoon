import sys
sys.setrecursionlimit(10**9)
# 전위 순회 = dfs

graph = []
while True:
    # EOF 
    try:
        n = int(input())
        graph.append(n)

    except EOFError:
        break

def post(start, end):
    if start > end:
        return
    
    mid = end + 1
    for i in range(start + 1, end + 1):
        if graph[i] > graph[start]:
            mid = i
            break
    
    post(start + 1, mid - 1)
    post(mid, end)           
    print(graph[start])

post(0, len(graph) - 1)
