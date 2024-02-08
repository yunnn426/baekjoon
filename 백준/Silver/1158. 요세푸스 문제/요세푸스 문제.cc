#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    queue<int> q;
    queue<int> answer;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    int cnt = 1;
    while (answer.size() != n) {
        int num = q.front();
        q.pop();
        if (cnt % k == 0) {
            answer.push(num);
        }
        else {
            q.push(num);
        }
        cnt += 1;
    }
    
    cout << "<";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << answer.front();
        }
        else {
            cout << answer.front() << ", ";
        }
        answer.pop();
    }
    cout << ">\n";

    return 0;
}

