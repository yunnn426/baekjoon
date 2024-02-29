#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
vector<vector<int>> v;

void hanoi(int n, int from, int mid, int to) {
    if (n == 1) {
        answer += 1;
        vector<int> vv;
        vv.push_back(from); vv.push_back(to);
        v.push_back(vv);
        return;
    }
    hanoi(n - 1, from, to, mid);
    hanoi(1, from, mid, to);
    hanoi(n - 1, mid, from, to);
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    // n-1번째까지의 원판을 2번 장대로 옮기고
    // n번째 원판을 3번 장대로 옮기고
    // 2번 장대의 원판들을 3번 장대로 옮김
    hanoi(n, 1, 2, 3);
    
    cout << answer << "\n";
    for (auto& iter : v) {
        cout << iter[0] << " " << iter[1] << "\n";
    }
    
    return 0;
}
