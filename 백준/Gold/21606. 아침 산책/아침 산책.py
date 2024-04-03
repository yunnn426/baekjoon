import sys
sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline())

inside = [-1 for _ in range(n + 1)] # 실내 여부 1: 실내, 0: 실외
string = sys.stdin.readline().strip()
for i in range(len(string)):
    inside[i + 1] = int(string[i])

graph = [[] for _ in range(n + 1)]
answer = 0
for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)
    # 실내 -> 실내 * 2
    if inside[a] == 1 and inside[b] == 1:
        answer += 2

visited = [0 for _ in range(n + 1)]
temp = 0
def dfs(x):
    for i in graph[x]:
        if visited[i] != 0:
            continue
        
        if inside[i] == 1:
            global temp
            temp += 1
        else:
            visited[i] = 1
            dfs(i) # 재귀할 때만 visit

    return temp
        

for i in range(1, n + 1):
    # 실외에 연결된 실내 노드 개수 n을 구하고
    # n * (n - 1)이 가능한 경로 수
    temp = 0
    if inside[i] == 1: 
        continue

    if visited[i] != 0:
        continue
    visited[i] = 1
    result = dfs(i)

    answer += result * (result - 1)
    
print(answer)