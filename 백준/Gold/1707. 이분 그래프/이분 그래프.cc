#include <iostream>
#include <vector>

using namespace std;

int k, v, e;
vector<vector<int>> graph(20005);
int visited[20005] = {0,};
bool answer = true;

// visited == 1: Red, visited == 2: Black
void dfs(int x, int rb) {
    for (int i = 0; i < graph[x].size(); i++) {
        if (visited[graph[x][i]] == 0) {
            int color = (rb % 2 == 1) ? 1 : 2;
            visited[graph[x][i]] = color;
            //cout << graph[x][i] << " ";
            dfs(graph[x][i], rb + 1);
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> k;
    
    for (int tc = 0; tc < k; tc++) {
        cin >> v >> e;
        answer = true;
        
        // 벡터 초기화
        for (int i = 1; i <= v; i++) {
            graph[i].clear();
        }
        fill(visited, visited + 20001, 0);
        
        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for (int i = 1; i <= v; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                //cout << i << " ";
                dfs(i, 2); // dfs로 노드 방문하며 r-b-r-b-... 색칠
            }
            
        }
        
        for (int i = 1; i <= v; i++) {
            int color = visited[i];
            for (int j = 0; j < graph[i].size(); j++) {
                if (visited[graph[i][j]] == color) {
                    answer = false;
                    break;
                }
            }
            if (answer == false)
                break;
        }
        
        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

