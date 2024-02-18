#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int> > map;
queue<tuple<int, int, int>> q;
bool arrive = false;
int answer = INT_MAX;
int n, m;
int visited[105][105] = {0,};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void search() {
    
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int s = get<2>(q.front());
        q.pop();
        
        // 종료 조건
        if (x == n - 1 && y == m - 1) {
            arrive = true;
            if (s < answer) {
                answer = s;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 맵 바깥 패스
                continue;
            if (map[nx][ny] == 0) // 벽 패스
                continue;
            if (visited[nx][ny] != 0) // 이미 방문한 경우 패스
                continue;
            visited[nx][ny] = 1;
            q.push(make_tuple(nx, ny, s + 1));
        }
        
    }
        
    
}

int solution(vector<vector<int> > maps)
{
    map = maps;
    n = maps.size();
    m = maps[0].size();
    
    q.push(make_tuple(0, 0, 1));
    search();
    
    if (!arrive)
        answer = -1;
    
    return answer;
}