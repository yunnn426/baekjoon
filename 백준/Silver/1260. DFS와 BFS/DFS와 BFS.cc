
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, v;
vector<pair<int, int>> edges;
int visited[1005] = {0,};
int visited2[1005] = {0,};
queue<int> bfs_q;

void dfs(int x) {
    for (auto iter = edges.begin(); iter != edges.end(); iter++) {
        if (iter->first == x && visited[iter->second] == 0) {
            cout << iter->second << " ";
            visited[iter->second] = 1;
            dfs(iter->second);
        }
    }
}

void bfs() {
    if (bfs_q.size() == 0) {
        return;
    }
    else {
        int x = bfs_q.front();
        bfs_q.pop();
        
        for (auto iter = edges.begin(); iter != edges.end(); iter++) {
            if (iter->first == x && visited2[iter->second] == 0) {
                cout << iter->second << " ";
                visited2[iter->second] = 1;
                bfs_q.push(iter->second);
            }
        }
        bfs();
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    
    cin >> n >> m >> v;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back(make_pair(x, y));
        edges.push_back(make_pair(y, x));
    }
    sort(edges.begin(), edges.end());
    
//    cout << endl;
//    for (auto iter = edges.begin(); iter != edges.end(); iter++) {
//        cout << iter->first << " " << iter->second << endl;
//    }
    
    // 1. DFS
    cout << v << " ";
    visited[v] = 1;
    dfs(v);
    cout << "\n";
    
    // 2. BFS
    cout << v << " ";
    visited2[v] = 1;
    bfs_q.push(v);
    bfs();
    
    return 0;
}

