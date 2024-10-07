import sys
input = sys.stdin.readline

s = input().rstrip()
t = input().rstrip()
answer = 0

while len(t) != len(s):
    last = t[-1]

    # 마지막 자 제외
    t = t[:len(t) - 1]
    if last == 'B': # B면 뒤집기
        t = t[::-1]

if s == t:
    print(1)
else:
    print(0)