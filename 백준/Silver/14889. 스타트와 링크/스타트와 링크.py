import sys, heapq
input = sys.stdin.readline

n = int(input())
stats = [list(map(int, input().split())) for _ in range(n)]
visited = [0 for _ in range(n)]
answer = 1e9

def cal_sum(st):
    sum = 0
    for i in st:
        for j in st:
            sum += stats[i][j]
    
    return sum

def dfs(idx, st):
    if len(st) == n / 2:
        st2 = [] # 다른 한 쪽 팀
        for i in range(n):
            if i not in st:
                st2.append(i)

        sum1 = cal_sum(st)
        sum2 = cal_sum(st2)
        global answer
        answer = min(answer, abs(sum1 - sum2))
        return
    
    for i in range(idx + 1, n):
        if visited[i] != 0:
            continue
        visited[i] = 1
        st.append(i)
        dfs(i, st)
        st.pop()
        visited[i] = 0

# 가능한 모든 선수 조합 찾기
for i in range(n):
    if visited[i] != 0:
        continue
    
    visited[i] = 1
    st = []
    st.append(i)
    dfs(i, st)

print(answer)