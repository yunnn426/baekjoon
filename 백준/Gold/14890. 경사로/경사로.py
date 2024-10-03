import sys
input = sys.stdin.readline

n, l = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
answer = 0

def check_slope(arr, start, end, val, visited):
    # start부터 end에 위치한 값이 val이어야 함
    for i in range(start, end + 1):
        # 범위 밖이거나 이미 다른 경사로가 놓여져 있으면 false
        if not 0 <= i < n or visited[i] != 0 or arr[i] != val:
            return False

        visited[i] = 1
    
    return True

def check_row(arr):
    visited = [0 for _ in range(n)]
    for j in range(n - 1):
        # 같은 높이 패스
        if arr[j] - arr[j + 1] == 0:
            continue

        # 차이 1보다 크면 지나갈 수 없는 길
        if abs(arr[j] - arr[j + 1]) > 1:
            return False
        
        # 경사로 놓을 수 있나 확인
        # 1. 높아지는 경우
        if arr[j] - arr[j + 1] == -1:
            if not check_slope(arr, j - l + 1, j, arr[j + 1] - 1, visited):
                return False
            
        # 2. 낮아지는 경우
        if arr[j] - arr[j + 1] == 1:
            if not check_slope(arr, j + 1, j + l, arr[j] - 1, visited):
                return False
    
    return True
            
# 행
for i in range(n):
    if check_row(board[i]):
        answer += 1

# 열
for j in range(n):
    if check_row([board[i][j] for i in range(n)]):
        answer += 1

print(answer)