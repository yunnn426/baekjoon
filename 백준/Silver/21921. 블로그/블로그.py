import sys
input = sys.stdin.readline

n, x = map(int, input().split())
visit = list(map(int, input().split()))

# 1 ~ x일 동안 들어온 방문자 수
window = sum(visit[:x])
answer = window
cnt = 1

for i in range(x, n):
    window -= visit[i - x]
    window += visit[i]
    
    if window >= answer:
        if window == answer:
            cnt += 1
        else:
            answer = window
            cnt = 1

if answer == 0:
    print('SAD')
else:
    print(answer, cnt, sep="\n")