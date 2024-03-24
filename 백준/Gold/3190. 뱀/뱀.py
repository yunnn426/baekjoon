import sys

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())
game = [[0 for j in range(105)] for i in range(105)] #105*105 arr

# 0: empty, 1: apple
for _ in range(k):
    x, y = map(int, sys.stdin.readline().split())
    game[x - 1][y - 1] = 1

l = int(sys.stdin.readline())

move = []
for i in range(l):
    x, c = map(str, sys.stdin.readline().split())
    move.append([x, c])

head = "right"
headx = 0
heady = 0
answer = 0
snakeQ = []
snakeQ.append([0, 0])

for i in range(1, 10010):
    # 머리 이동
    if head == "right":
        heady += 1
    elif head == "left":
        heady -= 1
    elif head == "down":
        headx += 1
    elif head == "up":
        headx -= 1

    if headx >= n or headx < 0 or heady < 0 or heady >= n: # 벽 충돌
        answer = i
        break
    if [headx, heady] in snakeQ: # 몸에 충돌
        answer = i
        break
    snakeQ.append([headx, heady])
    if game[headx][heady] != 1: # 사과 없으면 큐에서 뺌
        snakeQ.pop(0)
    else: # 사과 먹어서 치움
        game[headx][heady] = 0
        
    # X초에서 방향 전환
    if len(move) != 0 and i == int(move[0][0]): 
        if move[0][1] == "D":
            if head == "right": 
                head = "down"
            elif head == "left": 
                head = "up"
            elif head == "down": 
                head = "left"
            elif head == "up": 
                head = "right"
        if move[0][1] == "L":
            if head == "right": 
                head = "up"
            elif head == "left": 
                head = "down"
            elif head == "down": 
                head = "right"
            elif head == "up": 
                head = "left"
        move.pop(0) # 방향 전환 deq

print(answer)