#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> board;
int answer = 1e9;

void bfs(int dstx, int dsty) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    vector<vector<int>> visited(dstx, vector<int> (dsty, 0));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 1));
    visited[0][0] = 1;
    
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int step = get<2>(q.front());
        q.pop();
        
        if (x == dstx - 1 && y == dsty - 1) 
            answer = min(answer, step);
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= dstx || ny < 0 || ny >= dsty)
                continue;
            if (board[nx][ny] != 1)
                continue;
            if (visited[nx][ny] != 0)
                continue;
            
            q.push(make_tuple(nx, ny, step + 1));
            visited[nx][ny] = 1;
        }
    }
}

int solution(vector<vector<int>> maps)
{
    board = maps;
    int n = maps.size();
    int m = maps[0].size();
    
    bfs(n, m);
    
    if (answer == 1e9)
        answer = -1;
    
    return answer;
}