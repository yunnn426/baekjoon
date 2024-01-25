#include <iostream>
#include <limits.h>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int dp[5010];
    fill(dp, dp + 5010, INT_MAX - 10);
    
    dp[3] = 1;
    dp[4] = -1;
    dp[5] = 1;
    
    for (int i = 6; i <= n; i++) {
        if ((i - 5) >= 3) { // i == 8 이상
            if ((dp[i - 3] != -1) && (dp[i - 5] != -1)) {
                dp[i] = min(dp[i - 5] + 1, dp[i - 3] + 1);
            }
            else if (dp[i - 3] != -1) {
                dp[i] = dp[i - 3] + 1;
            }
            else if (dp[i - 5] != -1) {
                dp[i] = dp[i - 5] + 1;
            }
            else {
                dp[i] = -1;
            }
            //cout << dp[i] << endl;
        }
        else { // i == 6, 7
            if (dp[i - 3] != -1) {
                dp[i] = dp[i - 3] + 1;
            }
            else {
                dp[i] = -1;
            }
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
