from copy import deepcopy
import sys
input = sys.stdin.readline

n = int(input())
egg = [list(map(int, input().split())) for _ in range(n)]
answer = 0

# 최종 배열에서 몇 개가 깨졌는지 세기
def count(arr):
    cnt = 0
    # print(arr)
    for d, w in arr:
        if d <= 0:
            cnt += 1
    
    return cnt

def dfs(now, cnt, arr):
    # print('cnt:', cnt, arr)
    # 종료
    if cnt == n:
        global answer
        answer = max(answer, count(arr))
        return

    nd, nw = egg[now]

    # 손에 든 계란이 깨졌으면 다음 계란으로 넘어간다.
    if nd <= 0:
        dfs(now + 1, cnt + 1, arr)
        return
    
    flag = False
    for i in range(n):
        d, w = arr[i]

        # 깨진 계란 / 자기 자신을 칠 수 없다.
        if d <= 0 or now == i:
            continue
        
        arr[i] = [d - nw, w]
        arr[now] = [nd - w, nw]
        flag = True
        dfs(now + 1, cnt + 1, arr)
        arr[i] = [d, w]
        arr[now] = [nd, nw]
    
    # 칠게 아무것도 없으면 다음 계란으로
    if not flag:
        dfs(now + 1, cnt + 1, arr)

dfs(0, 0, egg)

print(answer)