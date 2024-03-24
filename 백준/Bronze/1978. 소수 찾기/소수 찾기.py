import sys
n = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))
answer = 0
for i in lst:
    answer += 1
    if i == 1: # 1은 소수 아님
        answer -= 1
    for j in range(2, i): # 나눠 떨어지면 소수 아님
        if i / j == i // j:
            answer -= 1
            break
print(answer)