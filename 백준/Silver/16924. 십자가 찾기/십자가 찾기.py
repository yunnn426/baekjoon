import sys, copy
input = sys.stdin.readline

n, m = map(int, input().split())
grid = [list(input().strip()) for _ in range(n)]
grid_copy = copy.deepcopy(grid)

def horizontal(x, y):
    # x, y를 중심으로 십자가의 가로를 확인한다.

    # 왼쪽
    i, j = x, y
    left = 0
    while 0 <= j and grid[i][j] == '*':
        left += 1
        j -= 1
    
    # 오른쪽
    i, j = x, y
    right = 0
    while j < m and grid[i][j] == '*':
        right += 1
        j += 1

    return min(left, right) - 1
    
def vertical(x, y):
    # x, y를 중심으로 십자가의 세로를 확인한다.

    # 위쪽 
    i, j = x, y
    up = 0
    while 0 <= i and grid[i][j] == '*':
        up += 1
        i -= 1  
    
    # 오른쪽
    i, j = x, y
    down = 0
    while i < n and grid[i][j] == '*':
        down += 1
        i += 1
    
    return min(up, down) - 1

# x, y를 중심으로 sz 크기의 십자가를 만들 수 있다고 표시한다.
def mark(x, y, sz):
    # 가로
    for i in range(y - sz, y + sz + 1, 1):
        grid_copy[x][i] = '.'
    
    # 세로
    for j in range(x - sz, x + sz + 1, 1):
        grid_copy[j][y] = '.'

def sol():
    answer = []
    # 가능한 십자가의 최대 크기
    size = (min(n, m) - 1) // 2

    # 가능한 십자가 중심점에서 그려질 수 있는 십자가 모두 체크
    # 행
    for i in range(n):
        # 열
        for j in range(m):
            if grid[i][j] != '*':
                continue

            h = horizontal(i, j)
            v = vertical(i, j)
            s = min(h, v)
            
            # 십자가 만들 수 있으면
            if s > 0:
                mark(i, j, s)
                answer.append([i, j, s])

    for i in range(n):
        if '*' in grid_copy[i]:
            return -1
    
    return answer
    
answer = sol()
if answer == -1:
    print(-1)
else:
    print(len(answer))
    for x, y, s in answer:
        print(x + 1, y + 1, s)
