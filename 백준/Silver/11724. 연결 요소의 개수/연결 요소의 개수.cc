#include <iostream>

using namespace std;

int n, m;
int graph[1005][1005] = {0,};
int visited[1005] = {0,};
int answer = 0;

void search(int k) { // 해당 정점에 연결되어있는 모든 정점 출력
    for (int j = 1; j <= n; j++) {
        if (graph[k][j] != 0 && visited[j] == 0) {
            //cout << j << " ";
            visited[j] = 1;
            search(j);
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    for (int i = 1; i <= n; i++) { // 1번 노드부터 돌면서 연결되어 있는 노드 찾기
        if (visited[i] == 0) {
            visited[i] = 1;
            //cout << i << " ";
            answer += 1; // 방문하지 않은 노드 == 새로운 연결 요소
        }
        search(i);
    }
    
    cout << answer << "\n";
    
    return 0;
}

