#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, answer = 0;
int board[20][20] = {0,};
vector<pair<int, int>> queen; // 퀸의 위치 저장

bool attack(int x, int y) {
    for (int s = 0; s < queen.size(); s++) {
        int i = queen[s].first;
        int j = queen[s].second;
        
        if (x == i) // 퀸 수평 상에 존재
            return true;
        if (y == j) // 퀸 수직 상에 존재
            return true;

        if (abs(x - i) == abs(y - j)) // 퀸 대각선 상에 존재
            return true;
    }
    
    return false;
}

void search(int x, int y) {
    if (x == n - 1) {
        answer += 1;
        return;
    }
    
    // 다음 행에 퀸을 놓을 자리 체크
    int i = x + 1;
    for (int j = 0; j < n; j++) {
        if (board[i][j] != 0)
            continue;
        if (attack(i, j))
            continue;
        
        board[i][j] = 8;
        queen.push_back(make_pair(i, j));
        search(i, j);
        board[i][j] = 0;
        queen.pop_back();
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n;

    // 퀸은 수평, 수직, 대각선 이동 가능
    for (int i = 0; i < n; i++) {
        fill(&board[0][0], &board[19][20], 0); // 0: 놓을 수 있음, 1: 놓을 수 없음
        queen.push_back(make_pair(0, i));
        board[0][i] = 8;
        search(0, i);
        queen.pop_back();
        board[0][i] = 0;
    }
    cout << answer << "\n";

    return 0;
}
