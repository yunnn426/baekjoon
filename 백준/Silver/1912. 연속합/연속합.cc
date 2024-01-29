#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int num[100010] = {0,};
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    int dp[100010];
    fill(dp, dp + 100010, INT_MIN);
    dp[0] = num[0];
    int answer = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + num[i], num[i]);
        answer = max(dp[i], answer);
    }
    
    cout << answer << "\n";
    
    return 0;
}

