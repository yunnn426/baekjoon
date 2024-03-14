#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, answer = 0;
vector<vector<int>> tmpmap;

void virus(int a, int b) { // bfs
    int visited[10][10] = {0,};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    queue<pair<int, int>> q;
    visited[a][b] = 1;
    q.push(make_pair(a, b));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] != 0)
                continue;
            if (tmpmap[nx][ny] != 0)
                continue;
            
            tmpmap[nx][ny] = 3;
            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    vector<vector<int>> map;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        map.push_back(v);
    }
    
    // 벽 (a,b), (c,d), (e,f)에 세움
    tmpmap = map;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (tmpmap[a][b] != 0)
                continue;
            
            for (int c = 0; c < n; c++) {
                for (int d = 0; d < m; d++) {
                    if (tmpmap[c][d] != 0)
                        continue;
                    if (c < a)
                        continue;
                    if (c == a && d <= b)
                        continue;
                    
                    for (int e = 0; e < n; e++) {
                        for (int f = 0; f < m; f++) {
                            if (tmpmap[e][f] != 0)
                                continue;
                            if (e < c)
                                continue;
                            if (e == c && f <= d)
                                continue;

                            tmpmap[a][b] = 1;
                            tmpmap[c][d] = 1;
                            tmpmap[e][f] = 1;
                            
                            // 바이러스 퍼짐
                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < m; j++) {
                                    if (tmpmap[i][j] == 2)
                                        virus(i, j);
                                }
                            }
                            
                            int tmpmax = 0;
                            // 안전 영역 세기
                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < m; j++) {
                                    if (tmpmap[i][j] == 0)
                                        tmpmax += 1;
                                }
                            }
                            answer = max(tmpmax, answer);
                            
                            // 초기화
                            tmpmap = map;
                        }
                    }
                    
                }
            }
        }
    }
    cout << answer << "\n";
    
    return 0;
}