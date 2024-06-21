from collections import deque

def bfs(place, i, j):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    visited = [[0 for _ in range(5)] for _ in range(5)]
    
    q = deque()
    q.append((i, j, 0))     # x - y - 맨해튼 거리
    visited[i][j] = 1

    while q:
        x, y, dist = q.popleft()

        # 다른 사람과 만나면 맨해튼 거리 비교
        if (place[x][y] == 'P' and (x != i or y != j)):
            if (dist <= 2):
                # print("(", i, ",", j, ")", "x:", x, "y:", y, "dist:", dist)
                return False
            
        for idx in range(4):
            nx = x + dx[idx]
            ny = y + dy[idx]
            
            if (nx < 0 or nx >= 5 or ny < 0 or ny >= 5):
                continue
            if (visited[nx][ny] != 0):
                continue
            if (place[nx][ny] == 'X'):
                continue
            
            q.append((nx, ny, dist + 1))
            visited[nx][ny] = 1
    
    return True
        
def solution(places):
    answer = []

    for p in range(len(places)):
        p_arr = []
        place = places[p]   # 지금 볼 대기실

        # p가 있는 곳을 다 구한다.
        for i in range(5):
            for j in range(5):
                if place[i][j] == 'P':
                    p_arr.append((i, j))
                    
        # p_arr에서 하나씩 꺼내서 bfs
        distancing = True
        for i in range(len(p_arr)):
            px = p_arr[i][0]
            py = p_arr[i][1]
            
            ok = bfs(place, px, py)
            if not ok:
                distancing = False
                break
        if distancing:
            answer.append(1)
        else:
            answer.append(0)
                
    return answer