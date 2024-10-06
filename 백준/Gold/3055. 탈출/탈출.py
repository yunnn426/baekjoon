from collections import deque
import sys
input = sys.stdin.readline

r, c = map(int, input().split())
forest = [list(input().rstrip()) for _ in range(r)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# letter의 모든 위치 찾기
def find(letter):
    arr = []
    for i in range(r):
        for j in range(c):
            if forest[i][j] == letter:
                arr.append([i, j])

    return arr 

# 물 확장
def bfs(letter):
    arr = find(letter)
    q = deque(arr)
    moved = False
    
    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if not 0 <= nx < r or not 0 <= ny < c:
                continue
            if forest[nx][ny] != '.':
                continue

            forest[nx][ny] = letter
            moved = True
    
    return moved

def check():
    for i in range(4):
        nx = di + dx[i]
        ny = dj + dy[i]

        if not 0 <= nx < r or not 0 <= ny < c:
            continue

        if forest[nx][ny] == 'S':
            return True
     
    return False

# 물 bfs => 비버 bfs
di, dj = find('D')[0] #  굴 위치
answer = 0
while True:
    found = check() # 다음 시간에 이동 가능한지 확인
    answer += 1
    
    # 이동 가능
    if found:
        break
    

    bfs('*')
    moved = bfs('S')

    # 이동 불가
    if not moved:
        answer = 'KAKTUS'
        break

print(answer)