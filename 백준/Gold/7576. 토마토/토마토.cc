#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int answer = 0;
int m, n;
int tomato[1005][1005];
int visited[1005][1005] = {0,};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<tuple<int, int, int>> q; // x - y - count

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> m >> n;
    fill(&tomato[0][0], &tomato[1004][1005], 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            tomato[i][j] = tmp;
            if (tmp == 1) {
                visited[i][j] = 1;
                q.push(make_tuple(i, j, 0));
            }
        }
    }
    
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();
        
        if (answer < cnt)
            answer = cnt;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (visited[nx][ny] != 0) // 이미 방문
                continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위 밖
                continue;
            if (tomato[nx][ny] != 0) // 이미 익었으면
                continue;
            visited[nx][ny] = 1;
            tomato[nx][ny] = 1;
            q.push(make_tuple(nx, ny, cnt + 1));
        }
    }
    
    bool all = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0)
                all = false;
        }
    }
    
    if (!all)
        answer = -1;
    
    cout << answer << "\n";
    
    return 0;
}
