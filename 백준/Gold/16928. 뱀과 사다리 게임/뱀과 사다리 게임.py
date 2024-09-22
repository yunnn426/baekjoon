from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
ladder = [tuple(map(int, input().split())) for _ in range(n)]
snake = [tuple(map(int, input().split())) for _ in range(m)]

def bfs(i):
    q = deque()
    q.append((1, 0)) # 시작 위치 - 주사위 굴린 횟수
    visited = [0 for _ in range(101)]
    visited[1] = 1
    answer = 1e9

    while q:
        x, cost = q.popleft()

        # 100번 칸에 도착
        if x == 100:
            answer = min(answer, cost)
            break
        
        for dx in range(1, 7):
            nx = x + dx
            if nx > 100 or visited[nx] != 0:
                continue

            general = True # 아무 것도 없는 칸인가

            # 사다리가 있으면
            for la, lb in ladder:
                if la == nx:
                    q.append((lb, cost + 1))
                    visited[lb] = 1
                    general = False
                    break
            
            # 뱀이 있으면
            for sa, sb in snake:
                if sa == nx:
                    q.append((sb, cost + 1))
                    visited[sb] = 1
                    general = False
                    break
            
            if general:
                q.append((nx, cost + 1))
                visited[nx] = 1

    return answer

print(bfs(0))