import sys
input = sys.stdin.readline

s = input().rstrip()
n = len(s)
add = 0

while True:
    # 문자열 뒤집기
    r = s[::-1]

    pal = True
    for i in range(n + add):
        if s[i] == '0' or r[i] == '0':
            continue
        if s[i] != r[i]:
            pal = False
    
    if pal: break

    # s 뒤에 0 추가, r 뒤에 0 추가
    # 다시 비교
    s = s + '0'
    r = '0' + r
    add += 1

print(n + add)