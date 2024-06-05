#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int f, s, g, u, d, answer = 1e9;
    cin >> f >> s >> g >> u >> d;
    
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    vector<int> record(f + 1, 1e9);     // 최장거리로 초기화
    record[s] = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        if (x == g) {
            answer = min(answer, cost);
        }
        
        if (x + u <= f && cost + 1 < record[x + u]) {    // 건물의 최상층은 f층이다.
            q.push(make_pair(x + u, cost + 1));
            record[x + u] = cost + 1;
        }
        if (x - d >= 1 && cost + 1 < record[x - d]) {    // 건물의 최하층은 1층이다.
            q.push(make_pair(x - d, cost + 1));
            record[x - d] = cost + 1;
        }
    }
    
    if (answer == 1e9)
        cout << "use the stairs\n";
    else
        cout << answer << "\n";
    
    return 0;
}
