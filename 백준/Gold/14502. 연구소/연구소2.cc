#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int bfs(vector<vector<int>> lab) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int> (m, 0));
    
    // 바이러스 위치 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 2) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }
    
    // 감염
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (lab[nx][ny] != 0)
                continue;
            if (visited[nx][ny] != 0)
                continue;
            
            lab[nx][ny] = 2;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = 1;
        }
    }
    
    // 안전영역 구하기
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0)
                cnt += 1;
        }
    }
    
    return cnt;
}

int main(void) {
    cin >> n >> m;
    vector<vector<int>> lab(n);
    vector<int> comb(n * m, 0);
    fill(comb.end() - 3, comb.end(), 1);
    
    // input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            lab[i].push_back(tmp);
        }
    }
    
    /* 벽을 세울 위치 3곳을 조합을 통해 구한다. */
    int answer = 0;
    do {
        vector<vector<int>> lab_copy = lab;
        bool can = true;
        for (int i = 0; i < n * m; i++) {
            if (comb[i] == 1) {
                int x = i / m;
                int y = i % m;
                if (lab_copy[x][y] != 0)
                    can = false;
                
                lab_copy[x][y] = 1;
            }
        }
        
        if (!can)
            continue;
        
        /* 벽을 세울 수 있다면 그때의 안전영역의 개수를 구한다. */
        int cnt = bfs(lab_copy);
        answer = max(cnt, answer);
    } while (next_permutation(comb.begin(), comb.end()));
    
    cout << answer << "\n";
    
    return 0;
}
