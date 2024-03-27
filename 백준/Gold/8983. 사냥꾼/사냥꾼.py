import sys

m, n, l = map(int, sys.stdin.readline().split())

shoot = list(map(int, sys.stdin.readline().split()))
shoot.sort()
animal = []
hunted = [0 for _ in range(n)] # 사냥 여부 체크

for _ in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    animal.append(arr)

answer = 0
for a in animal: # 동물 위치에서 사냥 가능한 사대 찾기
    x, y = a[0], a[1]
    find1 = x - l + y # find1 ~ find2 범위 안에 사대가 존재하는지 찾기
    find2 = x + l - y

    start = 0
    end = len(shoot) - 1
    while start <= end:
        mid = (start + end) // 2

        if find1 <= shoot[mid] <= find2: # 사대 존재
            answer += 1
            break
        elif shoot[mid] > find2:
            end = mid - 1
        else:
            start = mid + 1
    
print(answer)