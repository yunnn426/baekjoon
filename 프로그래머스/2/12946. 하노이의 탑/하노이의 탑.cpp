#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int mid, int to) {
    if (n == 1) {
        //cout << from << ", " << to << endl;
        vector<int> v;
        v.push_back(from);
        v.push_back(to);
        answer.push_back(v);
        return;
    }
    
    hanoi(n - 1, from, to, mid); // n번째 원판 제외하고 n-1개의 원판을 2번째 기둥으로 옮김
    hanoi(1, from, mid, to); // n번째 원판을 3번째 기둥으로 옮김
    hanoi(n-1, mid, from, to); // 2번째 기둥에 있는 n-1개의 원판을 3번째 기둥으로 옮김
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    
    return answer;
}