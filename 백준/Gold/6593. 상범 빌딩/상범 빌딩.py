from collections import deque
import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1 ,1]
D = 6

def find_start(arr):
    for i in range(l):
        for j in range(r):
            for k in range(c):
                if arr[i][j][k] == 'S':
                    return (i, j, k)
    
    return (0, 0, 0)

def bfs(arr, visited, l, r, c):
    q = deque()
    sx, sy, sz = find_start(arr)
    q.append((sx, sy, sz, 0))
    visited[sx][sy][sz] = 1
    
    answer = 1e9
    while q:
        x, y, z, cost = q.popleft()

        # 출구
        if arr[x][y][z] == 'E':
            answer = min(answer, cost)
        
        for i in range(D):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]

            if not 0 <= nx < l or not 0 <= ny < r or not 0 <= nz < c:
                continue
            if visited[nx][ny][nz] != 0 or arr[nx][ny][nz] == '#':
                continue
            
            q.append((nx, ny, nz, cost + 1))
            visited[nx][ny][nz] = 1
    
    return answer

while True:
    l, r, c = map(int, input().split())

    # 종료
    if l == 0 and r == 0 and c == 0:
        break

    # 입력
    building = []
    for _ in range(l):
        building.append([list(input().rstrip()) for _ in range(r)])
        input()
    
    visited = [[[0 for _ in range(c)] for _ in range(r)] for _ in range(l)]
    answer = bfs(building, visited, l, r, c)

    if answer == 1e9:
        print('Trapped!')
    else:
        print('Escaped in', answer, 'minute(s).')