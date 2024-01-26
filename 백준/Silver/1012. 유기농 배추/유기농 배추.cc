#include <iostream>

using namespace std;

int t, m, n, k, answer = 0;
int arr[55][55] = {0,};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int visited[55][55] = {0,};

void search(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && ny >= 0) {
            if (arr[nx][ny] == 1 && visited[nx][ny] == 0) { // 방문 전인 인접한 배추가 있는 경우
                visited[nx][ny] = 1;
                search(nx, ny);
            }
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> t;

    while (t > 0) {
        for (int i = 0; i < 55; i++) { // 배열 초기화
            for (int j = 0; j < 55; j++) {
                arr[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        
//        cout << endl;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                cout << arr[i][j] << " ";
//            }
//            cout << endl;
//        }
        
        answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1 && visited[i][j] == 0) {// 배추 o, 방문 전
                    answer += 1;
                    search(i, j);
                }
            }
        }
        
        cout << answer << "\n";
        t -= 1;
    }
    
    return 0;
}

