#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();
    int dp[100005][4] = {0,};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0) {   // 첫줄 초기화
                dp[i][j] = land[i][j];
                continue;
            }
            
            // 이전 줄의 최대값 찾기
            // 단, 같은 열이 아닌 경우
            int last_max = 0;
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                last_max = max(dp[i - 1][k], last_max);
            }
            dp[i][j] = last_max + land[i][j];
        }
    }
    
    // 마지막 행의 제일 큰 값이 정답
    for (int j = 0; j < 4; j++) {
        answer = max(answer, dp[n - 1][j]);
    }
    
    return answer;
}