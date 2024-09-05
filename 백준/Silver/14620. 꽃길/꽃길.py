import sys
input = sys.stdin.readline

n = int(input())
price = [list(map(int, input().split())) for _ in range(n)]

visited = [[0 for _ in range(n)] for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
answer = 1e9

def dfs(cnt, cost):
    if cnt == 3:
        global answer
        answer = min(answer, cost)
        return
    
    for x in range(n):
        for y in range(n):
            if visited[x][y] != 0:
                continue
            
            plant = True
            
            # 심을 수 있는지 확인
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]

                if not 0 <= nx < n or not 0 <= ny < n or visited[nx][ny] != 0:
                    plant = False
                    break

            if not plant: continue
            # print(x, y, '에 심기, 개수:', cnt)

            # 심기
            tmp_cost = cost + price[x][y]
            visited[x][y] = 1
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]

                visited[nx][ny] = 1
                tmp_cost += price[nx][ny]

            dfs(cnt + 1, tmp_cost)

            # 방문 해제
            visited[x][y] = 0
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]

                visited[nx][ny] = 0

dfs(0, 0)

print(answer)