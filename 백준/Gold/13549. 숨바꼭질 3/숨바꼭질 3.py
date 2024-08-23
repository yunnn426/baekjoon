from collections import deque
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
visited = [1e9 for _ in range(100010)]

def bfs():
    q = deque()
    q.append((n, 0))
    visited[n] = 0
    answer = 1e9

    while q:
        x, time = q.popleft()

        if x == k:
            answer = min(answer, time)

        walk1 = x - 1
        walk2 = x + 1
        tp = 2 * x

        if 0 <= walk1 < 100010 and visited[walk1] > time:
            q.append((walk1, time + 1))
            visited[walk1] = time + 1
        if 0 <= walk2 < 100010 and visited[walk2] > time:
            q.append((walk2, time + 1))
            visited[walk2] = time + 1
        if 0 <= tp < 100010 and visited[tp] > time:
            q.append((tp, time))
            visited[tp] = time

    return answer

answer = bfs()
print(answer)