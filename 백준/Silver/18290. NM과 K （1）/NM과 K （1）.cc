#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int n, m, k, answer = INT_MIN;
int arr[15][15] = {0,};
int visited[15][15] = {0,};
vector<pair<int, int>> adj;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void findAdj(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        adj.push_back(make_pair(nx, ny));
    }
}

void popAdj() {
    for (int i = 0; i < 4; i++) {
        adj.pop_back();
    }
}

void search(int x, int y, int cnt, int sum) {
    if (cnt == k) {
        if (sum > answer) {
            answer = sum;
        }
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool isAdj = false;
            for (auto iter = adj.begin(); iter != adj.end(); iter++) {
                if (iter->first == i && iter->second == j) {
                    isAdj = true;
                }
            }
            // 인접한 칸이거나 방문한 칸이면 건너뜀
            if (isAdj || visited[i][j] != 0)
                continue;
            
            visited[i][j] = 1;
            findAdj(i, j);
            sum += arr[i][j];
            
            search(i, j, cnt + 1, sum);
            
            visited[i][j] = 0;
            popAdj();
            sum -= arr[i][j];
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 1;
            adj.clear();
            findAdj(i, j);
            search(i, j, 1, arr[i][j]);
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}

