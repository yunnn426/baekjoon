#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int dp[1000010] = {INT_MAX,};

int dp_sub1(int j) {
    return dp[j-1] + 1;
}

int dp_div2(int j) {
    return dp[j/2] + 1;
}

int dp_div3(int j) {
    return dp[j/3] + 1;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    
    dp[1] = 0; dp[2] = 1; dp[3] = 1; // DP 배열 초기화
    for (int j = 4; j <= n; j++) {
        if (j % 6 == 0) { // 구하는 수가 6의 배수
            dp[j] = min({dp_sub1(j), dp_div2(j), dp_div3(j)});
        }
        else if (j % 2 == 0) { // 구하는 수가 2의 배수
            dp[j] = min(dp_sub1(j), dp_div2(j));
        }
        else if (j % 3 == 0) { // 구하는 수가 3의 배수
            dp[j] = min(dp_sub1(j), dp_div3(j));
        }
        else {
            dp[j] = dp_sub1(j);
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}

