#include <iostream>
#include <cmath>

using namespace std;

int n, m, answer = 0;
int a[55][55];
int b[55][55];

void cal(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            a[i][j] = abs(a[i][j] - 1);
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            b[i][j] = s[j] - '0';
        }
    }
    
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (a[i][j] != b[i][j]) {
                cal(i, j);
                answer += 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j])
                answer = -1;
        }
    }
    cout << answer << "\n";
    
    return 0;
}
