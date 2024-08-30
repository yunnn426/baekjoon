import sys
input = sys.stdin.readline

k = int(input())
sign = list(input().split())
visited = [0 for _ in range(10)]
max_num = '0' * (k + 1)
min_num = '9' * (k + 1)

def dfs(idx, num):
    if idx == k:
        global max_num, min_num
        if int(max_num) < int(num):
            max_num = num
        if int(min_num) > int(num):
            min_num = num
        
        return
        
    for i in range(10):
        if visited[i] != 0:
            continue

        if sign[idx] == '<':
            if int(num[-1]) >= i:
                continue
        else:
            if int(num[-1]) <= i:
                continue
        
        visited[i] = 1
        dfs(idx + 1, num + str(i))
        visited[i] = 0

for i in range(10):
    visited[i] = 1
    dfs(0, str(i))
    visited[i] = 0

print(max_num, min_num, sep="\n")