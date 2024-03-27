import sys

m, n, l = map(int, sys.stdin.readline().split())

shoot = list(map(int, sys.stdin.readline().split()))
animal = []
hunted = [0 for _ in range(n)] # 사냥 여부 체크

for _ in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    animal.append(arr)

answer = 0
for i in shoot: # 각 사대에서
    start = [i, 0]

    for i in range(n): # 사냥할 수 있는 동물 체크
        if hunted[i] != 0: # 이미 사냥됨
            continue

        target = animal[i]
        dw = abs(target[0] - start[0])
        dh = abs(target[1] - start[1])

        if dw + dh <= l: # 사정거리 안이면
            answer += 1
            hunted[i] = 1

print(answer)