#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

int bfs(vector<vector<int>> friends, int from, int to) {
    queue<pair<int, int>> q;
    q.push(make_pair(from, 0));
    vector<int> visited(n + 1, 0);
    visited[from] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        if (x == to) {
            return cost;
        }
            
        
        for (int i = 1; i <= n; i++) {
            if (visited[i] != 0)
                continue;
            if (friends[x][i] != 1)  // 서로 친구가 아니다
                continue;
            
            q.push(make_pair(i, cost + 1));
            visited[i] = 1;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    vector<vector<int>> friends(n + 1, vector<int> (n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }
    
    int min_bacon = 1e9;
    int answer = 0;
    
    // a에서 b까지 케빈 베이컨을 구하고
    // 그 합을 구한다.
    for (int from = 1; from <= n; from++) {
        int sum = 0;
        for (int to = 1; to <= n; to++) {
            if (from == to)
                continue;
            
            sum += bfs(friends, from, to);
        }
        
        if (sum < min_bacon) {
            min_bacon = sum;
            answer = from;
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
