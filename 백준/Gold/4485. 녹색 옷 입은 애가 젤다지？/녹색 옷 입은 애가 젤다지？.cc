#include <iostream>
#include <queue>

using namespace std;

int N;
int cave[126][126];
int rupee[126][126];

void bfs() {
    queue<pair<int,int>> q;

    int dx[4] = {-1,1,0,0}; //상하좌우
    int dy[4] = {0,0,-1,1};

    rupee[0][0] = cave[0][0];
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) { // 맵 바깥
                continue;
            }
            if (rupee[nx][ny] <= rupee[x][y] + cave[nx][ny])
                continue;
            rupee[nx][ny] = rupee[x][y] + cave[nx][ny];

            q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    int problem = 1;
    while (true) {
        
        //cave, rupee 초기화
        fill(cave[0], cave[126], 0);
        fill(rupee[0], rupee[126], 999999);

        cin >> N;
        if (N == 0)
            break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cave[i][j];
            }
        }

        bfs();

        cout << "Problem " << problem << ": " << rupee[N-1][N-1] << endl;
        problem++;
    }

	return 0;
}