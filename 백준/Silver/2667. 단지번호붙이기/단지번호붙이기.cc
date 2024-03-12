#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, cnt = 0;
int map[30][30] = {0,};
int visited[30][30] = {0,};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> counts;

void dfs(int x, int y) {
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (visited[nx][ny] != 0)
            continue;
        if (map[nx][ny] == 0)
            continue;
        visited[nx][ny] = 1;
        cnt += 1;
        dfs(nx, ny);
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            map[i][j] = s[j] - '0';
        }
    }
    
    int blk = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] != 0)
                continue;
            if (map[i][j] == 0)
                continue;
            cnt = 1;
            visited[i][j] = 1;
            dfs(i, j);
            blk += 1;
            counts.push_back(cnt);
        }
    }
    
    cout << blk - 1 << "\n";
    if (counts.size() == 0)
        counts.push_back(0);
    sort(counts.begin(), counts.end());
    for (auto& iter : counts) {
        cout << iter << "\n";
    }
    
    return 0;
}
