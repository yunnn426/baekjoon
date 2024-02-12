#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    // dp[n][1]: n을 1로만 표현 = 1개
    // dp[n][2]: n을 오름차순으로 표현했을 때 가장 큰 수가 2
    //              dp[n - 2][1] 뒤에 2 추가 + dp[n - 2][2] 뒤에 2 추가
    // dp[n][3]: n을 오름차순으로 표현했을 때 가장 큰 수가 3
    //              dp[n - 3][1] 뒤에 3 추가 + dp[n - 3][2] 뒤에 3 추가 + dp[n - 3][3] 뒤에 3 추가
    // n = 7까지 직접 해보기
    int dp[10001][4];
    
    dp[1][1] = 1;
    
    dp[2][1] = 1; dp[2][2] = 1;
    
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
    
    for (int i = 4; i < 10001; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
    
    return 0;
}

