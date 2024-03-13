#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, k, answer = -1;
    cin >> n >> k;
    queue<pair<int, int>> q;
    int visited[100010] = {0,};
    visited[n] = 1;
    q.push(make_pair(n, 0));
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        if (now == k) {
            answer = cnt;
            break;
        }
        q.pop();
        
        if (now - 1 >= 0 && visited[now - 1] == 0) {
            visited[now - 1] = 1;
            q.push(make_pair(now - 1, cnt + 1));
        }
        if (now + 1 <= 100000 && visited[now + 1] == 0) {
            visited[now + 1] = 1;
            q.push(make_pair(now + 1, cnt + 1));
        }
        if (now * 2 <= 100000 && visited[now * 2] == 0) {
            visited[now * 2] = 1;
            q.push(make_pair(now * 2, cnt + 1));
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
