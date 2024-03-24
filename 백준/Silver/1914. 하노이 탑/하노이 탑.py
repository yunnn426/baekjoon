n = int(input())
answer = 0
lst = [] # 20개 이하
dp = [0 for _ in range(n + 1)] # 20개 이상

def hanoi(cnt, start, mid, end):
    # n - 1개를 가운데 장대로
    # n번째 원판을 마지막 장대로
    # 가운데 장대들을 마지막 장대로
    if cnt == 1:
        global answer
        answer += 1
        lst.append([start, end])
        return

    hanoi(cnt - 1, start, end, mid)
    hanoi(1, start, mid, end)
    hanoi(cnt - 1, mid, start, end)

if n <= 20:
    hanoi(n, 1, 2, 3)
    print(answer)
    for i in lst:
        print(i[0], i[1], sep=" ")

else:
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = 2 * dp[i - 1] + 1
    print(dp[n])