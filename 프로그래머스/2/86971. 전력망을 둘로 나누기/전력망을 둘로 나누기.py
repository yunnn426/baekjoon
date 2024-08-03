from collections import deque
 
cnt = 0
def dfs(cut, start, wires, visited):
    for i in range(len(wires)):
        dep, dst = wires[i]
        if i == cut:
            continue
        if dep != start and dst != start:
            continue
            
        global cnt
        
        if dep == start:
            if visited[dst] != 0:
                continue
            cnt += 1
            visited[dst] = 1
            dfs(cut, dst, wires, visited)
        else:
            if visited[dep] != 0:
                continue
            cnt += 1
            visited[dep] = 1
            dfs(cut, dep, wires, visited)

def solution(n, wires):
    answer = 1e9
    
    # i번째 전선 끊기
    for i in range(n - 1):
        visited = [0 for _ in range(n + 1)]
        count = []
        
        for j in range(1, n + 1):
            if visited[j] != 0:
                continue
            global cnt
            cnt = 1
            visited[j] = 1
            dfs(i, j, wires, visited)
            count.append(cnt)
        
        answer = min(answer, abs(count[0] - count[1]))
            
    return answer