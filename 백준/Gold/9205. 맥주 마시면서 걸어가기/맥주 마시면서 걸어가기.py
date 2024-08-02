from collections import deque
import sys
input = sys.stdin.readline

t = int(input())

def distance(x, y, nx, ny):
    return abs(x - nx) + abs(y - ny)

for _ in range(t):
    n = int(input())
    # 상근이네
    house_x, house_y = map(int, input().split())

    # 편의점
    conv = []
    for _ in range(n):
        conv_x, conv_y = map(int, input().split())
        conv.append((conv_x, conv_y))

    # 펜타포트
    fest_x, fest_y = map(int, input().split())

    answer = False
    visited = [0 for _ in range(n)]

    q = deque()
    q.append((house_x, house_y))
    while q:
        x, y = q.popleft()

        # 현재 위치에서 펜타포트에 갈 수 있다
        if distance(x, y, fest_x, fest_y) <= 1000:
            answer = True
            break

        # 1000 이내에 위치한 편의점 찾기
        for i in range(len(conv)):
            if visited[i] != 0:
                continue

            conv_x, conv_y = conv[i]

            if distance(x, y, conv_x, conv_y) <= 1000:
                q.append((conv_x, conv_y))
                visited[i] = 1

    if answer:
        print('happy')
    else:
        print('sad')