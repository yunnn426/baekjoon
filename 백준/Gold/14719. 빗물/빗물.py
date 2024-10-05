import sys
input = sys.stdin.readline

h, w = map(int, input().split())
blocks = list(map(int, input().split()))

answer = h * w - sum(blocks) # 흰 칸의 개수

# h 높이부터 내려오면서
# 빗물이 새는 블록을 뺀다.
for i in range(h, 0, -1):
    visited = [0 for _ in range(w)]

    # 왼 -> 오 체크
    for j in range(w):
        # 해당 층에서 빗물이 고일 수 있음
        if i <= blocks[j] or visited[j] != 0:
            break
        
        answer -= 1
        visited[j] = 1

    # 오 -> 왼 체크
    for j in range(w - 1, -1, -1):
        if i <= blocks[j] or visited[j] != 0:
            break

        answer -= 1
        visited[j] = 1

print(answer)