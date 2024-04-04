# 바닥 장식
import sys
input = sys.stdin.readline

# input
n, m = map(int, input().split())
floor = [[] for _ in range(n)]
for i in range(n):
    string = input()
    for j in range(m):
        floor[i].append(string[j])

visited = [[0 for _ in range(m)] for _ in range(n)]
answer = 0

for x in range(n):
    for y in range(m): 
        if visited[x][y] != 0:
            continue
        visited[x][y] = 1
        answer += 1

        # - 면 오른쪽 체크
        if floor[x][y] == '-':
            cnt = 1
            while True:
                if y + cnt < m and floor[x][y + cnt] == '-':
                    visited[x][y + cnt] = 1
                    cnt += 1
                else:
                    break
        
        # | 면 아래 체크
        elif floor[x][y] == '|':
            cnt = 1
            while True:
                if x + cnt < n and floor[x + cnt][y] == '|':
                    visited[x + cnt][y] = 1
                    cnt += 1
                else:
                    break
print(answer)