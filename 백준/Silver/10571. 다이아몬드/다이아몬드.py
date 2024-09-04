import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    dia = [list(map(float, input().split())) for _ in range(n)]

    dp = [1 for _ in range(n)]

    for i in range(1, n):
        wi, ci = dia[i]

        # 앞의 다이아들 중 최장 길이 구하기
        for j in range(0, i):
            wj, cj = dia[j]
            if wi > wj and ci < cj:
                dp[i] = max(dp[i], dp[j] + 1)
    
    print(max(dp))
