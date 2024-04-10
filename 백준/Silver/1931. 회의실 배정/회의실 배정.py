import sys
input = sys.stdin.readline

n = int(input())
schdl = []
for _ in range(n):
    s, e = map(int, input().split())
    schdl.append((e, s)) # 끝, 시작

# 끝나는 시간이 빠른 순으로 정렬
schdl.sort()
answer = 0
end = 0
start = 0
for i in schdl:
    if end == 0 and start == 0:
        end, start = i
        answer += 1
        continue

    e, s = i
    if s >= end:
        end, start = i
        answer += 1

print(answer)