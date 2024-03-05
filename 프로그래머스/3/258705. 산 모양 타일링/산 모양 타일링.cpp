#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    int dp[100010][4];
    
    // dp[n][0]: n번째 삼각형에 아무것도 안칠하는 경우
    // dp[n][1]: 왼쪽 두개 칠하는 경우
    // dp[n][2]: 오른쪽 두개 칠하는 경우
    // dp[n][3]: top에 칠하는 경우
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = tops[0];
    answer = 3 + tops[0];
    
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % 10007;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3]) % 10007;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % 10007;
        if (tops[i - 1] == 0)
            dp[i][3] = 0;
        else 
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % 10007;
        answer = (dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3]) % 10007;
    }
    
    return answer;
}