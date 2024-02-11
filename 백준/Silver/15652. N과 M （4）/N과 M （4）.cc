#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result;

void search(int x, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = x; i <= n; i++) {
        result.push_back(i);
        search(i, cnt + 1);
        result.pop_back();
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    search(1, 0);
    
    return 0;
}

