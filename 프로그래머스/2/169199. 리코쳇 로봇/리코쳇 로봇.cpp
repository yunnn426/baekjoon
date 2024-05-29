#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> board;
int answer = 1e9, n, m;
int rx, ry;     // R의 위치
int dist[105][105];
queue<tuple<int, int, int>> q;

void bfs() {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int cnt = 0;
    // 해당 위치까지 제일 가깝게 가는 경우를 저장하기 위해 
    fill(&dist[0][0], &dist[n - 1][m], 1e9);    
    
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();
        
        // 종료 조건
        if (board[x][y] == 'G') {
            answer = min(answer, cnt);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == 'D')
                continue;
            
            // 장애물 만날 때까지 미끄러지기
            while (true) {
                nx += dx[i];
                ny += dy[i];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'D') {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
            }
            
            // nx, ny까지 가는 더 짧은 길인 경우에만 큐에 추가
            if (cnt < dist[nx][ny]) {
                q.push(make_tuple(nx, ny, cnt + 1));
                dist[nx][ny] = cnt + 1;
            }
        }
    }
}

int solution(vector<string> boards) {
    board = boards;
    n = boards.size();      // 열
    m = boards[0].size();   // 행
    
    // 초기 R의 위치 찾기 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (boards[i][j] == 'R') {
                rx = i;
                ry = j;
                break;
            }
        }
    }
    
    q.push(make_tuple(rx, ry, 0));
    bfs();
    
    if (answer == 1e9)
        answer = -1;
    
    return answer;
}