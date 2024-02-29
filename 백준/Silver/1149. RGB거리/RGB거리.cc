#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    int cost[1005][3] = {0,};
    for (int i = 1; i <= n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    // dp[n][0] : n번째 집을 R로 칠하는 최소 비용
    // dp[n][1] : n번째 집을 G로 칠하는 최소 비용
    // dp[n][2] : n번째 집을 B로 칠하는 최소 비용
    int dp[1005][3] = {0,};
    int answer = 0;
    
    /*
     i번째 집을 R로 칠하면 최소비용 = 
     min(i-1번째 집을 G로 칠한 최소 비용, i-1번째 집을 B로 칠한 최소 비용)
     + i번째 집을 R로 칠하는 비용
     - 위 과정을 G, B에 대해 반복
     - 답은 세 가지 경우 중 최소값
    */
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        
        answer = min({dp[i][0], dp[i][1], dp[i][2]});
    }
    
    cout << answer << "\n";
    
    return 0;
}
