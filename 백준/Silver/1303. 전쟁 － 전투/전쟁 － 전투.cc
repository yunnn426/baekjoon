#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ground(m, vector<char> (n, 0));
    vector<vector<int>> visited(m, vector<int> (n, 0));
    
    // input
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            ground[i][j] = s[j];
        }
    }
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // bfs
    int w = 0, b = 0;
    queue<pair<int, int>> q;
    for (int mx = 0; mx < m; mx++) {
        for (int my = 0; my < n; my++) {
            if (visited[mx][my] != 0)
                continue;
            
            // 방문 전인 병사에 대하여 bfs
            q.push(make_pair(mx, my));
            visited[mx][my] = 1;
            int cnt = 0;
            
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                cnt += 1;
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (visited[nx][ny] != 0)
                        continue;
                    if (ground[nx][ny] != ground[x][y])
                        continue;
                    
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                }
            }
            
            if (ground[mx][my] == 'W')
                w += cnt * cnt;
            else
                b += cnt * cnt;
        }
    }
    
    cout << w << " " << b << "\n";
    
    return 0;
}
