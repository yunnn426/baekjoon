
from collections import deque
import sys
input = sys.stdin.readline

# input
n, m = map(int, input().split())
board = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    board[a].append(b)
    board[b].append(a)

# 각 헛간까지의 거리 무한으로 초기화
dijk = [1e9 for _ in range(n + 1)]
dijk[1] = 0
q = deque()
visited = [0 for _ in range(n + 1)]

# 1번 헛간부터 시작
q.append(1)
visited[1] = 1
while q:
    hut = q.popleft()
    cost = dijk[hut]

    for h in board[hut]:
        if visited[h] != 0:
            continue

        # hut과 연결된 헛간들은 hut까지의 거리 +1
        dijk[h] = min(dijk[h], cost + 1)
        
        q.append(h)
        visited[h] = 1

# 숨어야 하는 헛간 번호, 그 헛간까지의 거리, 같은 거리를 갖는 헛간의 개수
hide = 1
distance = 0
same = 1
for i in range(1, n + 1):
    if distance < dijk[i]:
        hide = i
        distance = dijk[i]
        same = 1
    
    elif distance == dijk[i]:
        same += 1

print(hide, distance, same)