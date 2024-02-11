#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> result;
int visited[10005] = {0,};

void search(int x, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[v[i]] != 0) continue;
        
        result.push_back(v[i]);
        visited[v[i]] = 1;
        search(i + 1, cnt + 1);
        visited[v[i]] = 0;
        result.pop_back();
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    search(0, 0);
    
    return 0;
}

