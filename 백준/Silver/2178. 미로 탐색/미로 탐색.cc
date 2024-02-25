#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    int maze[105][105] = {0,};
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            maze[i][j] = s[j - 1] - '0';
        }
    }
    
    queue<tuple<int, int, int>> q;
    int visited[105][105] = {0,};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int answer = 987654321;
    q.push(make_tuple(1, 1, 1));
    visited[1][1] = 1;
    
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        if (x == n && y == m) {
            if (cnt < answer) {
                answer = cnt;
            }
        }
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;
            if (visited[nx][ny] != 0)
                continue;
            if (maze[nx][ny] == 0)
                continue;
                
            visited[nx][ny] = 1;
            q.push(make_tuple(nx, ny, cnt + 1));
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
