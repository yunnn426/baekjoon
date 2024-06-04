#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0, ans1 = 0, ans2 = 0;     // 답, 레버까지, 종료까지
    int n = maps.size();
    int m = maps[0].size();
    
    /* 시작점 */
    int sx = 0, sy = 0;
    /* 레버 */
    int lx = 0, ly = 0;
    /* 출구 */
    int ex = 0, ey = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (maps[i][j] == 'L') {
                lx = i;
                ly = j;
            }
            if (maps[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    /* 1단계. 레버 찾기 */
    queue<tuple<int, int, int>> q1;
    q1.push(make_tuple(sx, sy, 0));
    int visited[105][105] = {0,};
    while (!q1.empty()) {
        int x = get<0>(q1.front());
        int y = get<1>(q1.front());
        int time = get<2>(q1.front());
        q1.pop();
        
        // 레버 도착
        if (x == lx && y == ly) {
            ans1 = time;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (visited[nx][ny] != 0)
                continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (maps[nx][ny] == 'X')
                continue;
            
            q1.push(make_tuple(nx, ny, time + 1));
            visited[nx][ny] = 1;
        }
    }
    // 레버를 찾지 못한 경우
    if (ans1 == 0)
        return -1;
    
    /* 2단계. 레버~종료지점 찾기 */
    queue<tuple<int, int, int>> q2;
    q2.push(make_tuple(lx, ly, 0));
    int visited2[105][105] = {0,};
    while (!q2.empty()) {
        int x = get<0>(q2.front());
        int y = get<1>(q2.front());
        int time = get<2>(q2.front());
        q2.pop();
        
        // 종료 도착
        if (x == ex && y == ey) {
            ans2 = time;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (visited2[nx][ny] != 0)
                continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (maps[nx][ny] == 'X')
                continue;
            
            q2.push(make_tuple(nx, ny, time + 1));
            visited2[nx][ny] = 1;
        }
    }
    // 도착점을 찾지 못한 경우
    if (ans2 == 0)
        return -1;
    
    answer = ans1 + ans2; 
    
    return answer;
}