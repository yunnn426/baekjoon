import sys
n = int(sys.stdin.readline())
costarr = []
visited = [0 for _ in range(n)]
answer = sys.maxsize

def search(start, to, cost, cnt):
    global answer
    
    if cost > answer: # 비용이 넘어선 경우 더 확인하지 않음
        return
    
    if cnt == n:
        if costarr[to][start] == 0: # 출발지로 돌아가는 길이 없음
            return
        else:
            cost += costarr[to][start] # 출발지로 돌아감
        answer = min(cost, answer)
        return

    for i in range(n):
        if costarr[to][i] == 0: # 방문 불가
            continue 
        if visited[i] != 0: # 이미 방문
            continue

        visited[i] = 1
        search(start, i, cost + costarr[to][i], cnt + 1)
        visited[i] = 0

if __name__ == '__main__':
    for _ in range(n):
        arr = list(map(int, sys.stdin.readline().split()))
        costarr.append(arr)

    # 1번 도시부터 완전탐색
    for i in range(n):
        visited[i] = 1
        search(i, i, 0, 1)
        visited[i] = 0

    print(answer)