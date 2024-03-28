# 더하기 사이클

import sys

n = int(sys.stdin.readline())
answer = 0
newn = -1
tempn = n
while True:
    if newn == n:
        break

    if tempn < 10:
        newn = 10 * tempn + tempn
    else:
        a = tempn // 10
        b = tempn % 10
        tmp = a + b
        newn = 10 * b + (tmp % 10)
    
    tempn = newn
    answer += 1

print(answer)