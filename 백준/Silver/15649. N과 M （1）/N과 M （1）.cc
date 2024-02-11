#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result;
int visited[10] = {0,};

void search(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i] != 0)
            continue;
        result.push_back(i);
        visited[i] = 1;
        search(cnt + 1);
        result.pop_back();
        visited[i] = 0;
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    search(0);
    
    return 0;
}

