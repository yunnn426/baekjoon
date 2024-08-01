def solution(triangle):
    answer = 0
    
    # dp 배열 초기화
    n = len(triangle)
    dp = [[] for _ in range(n)]
    dp[0].append(triangle[0][0])

    for i in range(1, n): # i번째 줄
        for j in range(i + 1): # j번째 수
            # 바로 윗줄 0번째 수에서만 갈 수 있음
            if j == 0:
                dp[i].append(dp[i - 1][j] + triangle[i][j])
            # 바로 윗줄 j - 1번째 수에서만 갈 수 있음
            elif j == i:
                dp[i].append(dp[i - 1][j - 1] + triangle[i][j])
            # 바로 윗줄 양쪽에서 갈 수 있음
            else:
                cost = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]
                dp[i].append(cost)
    
    answer = max(dp[n - 1])
    
    return answer