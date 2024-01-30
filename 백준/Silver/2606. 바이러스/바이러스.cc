#include <iostream>

using namespace std;

int n, t, answer = 0;
int arr[105][105] = {0,};
int visited[105] = {0,};

void warm(int k) {
    for (int i = 1; i <= n; i++) {
        if (arr[k][i] == 1 && visited[i] == 0) { // 해당 컴퓨터가 연결되어 있으면
            visited[i] = 1;
            //cout << "i: " << i << endl;
            answer += 1;
            warm(i);
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> t;
    
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    visited[1] = 1; // 1번 컴퓨터는 방문했다고 가정
    
    warm(1);

    cout << answer << "\n";
    
    return 0;
}