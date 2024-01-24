#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, d;
    cin >> n >> d;
    vector<tuple<int, int, int>> shortcuts;
    
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        shortcuts.push_back(make_tuple(a, b, c));
    }
    
    int dp[10010];
    fill_n(dp, 10010, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= d; i++) {
        bool hasshort = false;
        int x, y, dis;
        for (int j = 0; j < shortcuts.size(); j++) {
            hasshort = false;
            x = get<0>(shortcuts[j]);
            y = get<1>(shortcuts[j]);
            dis = get<2>(shortcuts[j]);
            if (y == i) { // 해당 위치까지의 지름길이 존재하는가
                hasshort = true;
            }
            if (hasshort) { // 지름길 있으면 (직전위치에서 +1) or (지름길 시작점까지 최단거리 + 지름길 길이) 중 작은 값
                dp[i] = min({dp[i], dp[i - 1] + 1, dp[x] + dis});
            }
            else {
                if (dp[i] == INT_MAX)
                    dp[i] = dp[i - 1] + 1; // 지름길 없으면 +1
            }
        }
    }
    
    cout << dp[d] << "\n";
    
    return 0;
}
