#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        int x, answer;
        cin >> x;
        if (x == 0) {
            if (pq.size() == 0)
                answer = 0;
            else {
                answer = pq.top();
                pq.pop();
            }
            cout << answer << "\n";
        }
        else {
            pq.push(x);
        }
    }
    
    return 0;
}
