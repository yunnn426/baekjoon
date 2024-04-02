import sys

n = int(sys.stdin.readline())

inside = [-1 for _ in range(n + 1)] # 실내 여부 1: 실내, 0: 실외
string = sys.stdin.readline().strip()
for i in range(len(string)):
    inside[i + 1] = int(string[i])

graph = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

answer = 0
visited = [0 for _ in range(n + 1)]
def dfs(start, x):
    if start != x and inside[x] == 1: # 시작 노드가 아닌 실내 노드 들어가면 경로 끝, 정답 ++
        global answer
        answer += 1
        return
    
    for i in graph[x]:
        if visited[i] != 0:
            continue
        visited[i] = 1
        dfs(start, i)
        

for i in range(1, n + 1):
    visited = [0 for _ in range(n + 1)]
    if inside[i] == 0: # 실외에서 시작할 수 없음
        continue
    visited[i] = 1
    dfs(i, i)

print(answer)