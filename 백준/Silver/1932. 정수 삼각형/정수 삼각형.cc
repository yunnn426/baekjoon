#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
vector<vector<int>> triangle;
int dp[505][505];

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = 0; j < i; j++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        triangle.push_back(v);
    }
    
    // dp[n][i] : n번째줄 i번째 수까지의 최대 합
    dp[0][0] = triangle[0][0];
    answer = dp[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][0] + triangle[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            answer = max(answer, dp[i][j]);
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
