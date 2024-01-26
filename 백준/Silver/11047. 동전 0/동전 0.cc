#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int n, k, answer = 0;
    cin >> n >> k;
    int coin[15];
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (coin[i] <= k) {
            answer += k / coin[i];
            k %= coin[i];
        }
    }
    cout << answer << "\n";
    
    return 0;
}

