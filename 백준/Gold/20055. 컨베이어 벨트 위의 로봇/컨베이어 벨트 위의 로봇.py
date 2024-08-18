import sys
input = sys.stdin.readline

n, k = map(int, input().split())
dur = list(map(int, input().split()))
robots = [0 for _ in range(2 * n)]
steps = 0
idx = 0 # 1번칸 기준

def stop():
    count = 0
    for d in dur:
        if d <= 0:
            count += 1
    
    return count

def print_belt(idx, lst):
    for i in range(n):
        if idx + i >= 2 * n:
            print('(', idx + i - 2 * n, ')', lst[idx + i - 2 * n], end="")
            if robots[idx + i - 2 * n] == 1:
                print('*', end=" ")
            else:
                print(' ', end="")
        else:
            print('(', idx + i, ')', lst[idx + i], end="")
            if robots[idx + i] == 1:
                print('*', end=" ")
            else:
                print(' ', end="")

    
    print()

    for i in range(n):
        # print(idx, i)
        if idx - i - 1 < 0:
            print('(', idx - i - 1 + 2 * n, ')', lst[idx - i - 1 + 2 * n], end=" ")
        else:
            print('(', idx - i - 1, ')', lst[idx - i - 1], end=" ")

    
    print()

while stop() < k:
    steps += 1

    # 한칸 회전
    idx -= 1
    if idx == -1:
        idx = 2 * n - 1

    # 내리는 위치
    drop = idx + n - 1
    if drop >= 2 * n:
        drop -= 2 * n
    if robots[drop] == 1:
        robots[drop] = 0

    # 로봇 이동
    for i in range(n - 2, -1, -1):
        # 인덱스
        j = idx + i + 1
        if j >= 2 * n:
            j -= 2 * n
        
        if robots[j - 1] == 0 or robots[j] == 1 or dur[j] < 1:
            continue

        # 한 칸 앞으로
        robots[j] = 1
        robots[j - 1] = 0
        dur[j] -= 1

    # 올리는 위치
    if dur[idx] > 0:
        dur[idx] -= 1
        robots[idx] = 1

    # 내리는 위치 다시 확인
    if robots[drop] == 1:
        robots[drop] = 0

    # print_belt(idx, dur)

print(steps)

# 0번쨰: 올리는 위치
# n-1번째: 내리는 위치
# 시작 위치 한칸씩 뒤로