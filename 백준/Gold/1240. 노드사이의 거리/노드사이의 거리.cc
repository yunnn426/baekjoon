#include <iostream>
#include <vector>

using namespace std;

int n, m, answer = 0;
vector<vector<pair<int, int>>> nodes(1005);
int visited[1005] = {0,};

void search(int a, int b) {
    for (int i = 0; i < nodes[a].size(); i++) {
        if (visited[nodes[a][i].first] != 0) {
            continue;
        }
            
        visited[nodes[a][i].first] = 1;
        answer += nodes[a][i].second;
        if (nodes[a][i].first == b) {
            cout << answer << endl;
            return;
        }
        
        search(nodes[a][i].first, b);
        
        // 방문 전으로 돌려놈
        answer -= nodes[a][i].second;
        visited[nodes[a][i].first] = 0;
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b, dist;
        cin >> a >> b >> dist;
        nodes[a].push_back(make_pair(b, dist));
        nodes[b].push_back(make_pair(a, dist));
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        answer = 0;
        visited[a] = 1;
        search(a, b);
        
        // 방문 전으로 돌려놈
        visited[a] = 0;
        visited[b] = 0;
    }
    
    return 0;
}

