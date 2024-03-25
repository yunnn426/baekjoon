n = int(input())
answer = 0
row = [0 for _ in range(n)]

def attack(x):
    for i in range(x):
        if row[x] == row[i]: # 수직 체크
            return True
        if abs(row[x] - row[i]) == abs(x - i): # 대각선 체크
            return True
    return False

def search(x):
    if x == n:
        global answer
        answer += 1
        return
    
    # 다음 행 체크
    for i in range(n):
        # [x, i]에 퀸
        row[x] = i
        if attack(x) == False: # 공격 가능한 위치 x
            search(x + 1)
        
search(0)

print(answer)