import sys, itertools
height = []
for _ in range(9):
    n = int(sys.stdin.readline())
    height.append(n)

com = itertools.combinations(height, 7) # 2개 제외한 모든 조합
answer = []

for i in com:
    sum = 0
    for j in i:
        sum += j
    if sum == 100:
        answer = i
    
srt = sorted(answer)
for i in srt:
    print(i)