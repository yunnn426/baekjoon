#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0, n = order.size();
    
    queue<int> belt;    // 컨베이어벨트
    stack<int> help;    // 보조
    vector<int> truck;  // 트럭
    
    // 컨베이어 벨트 초기화
    for (int i = 1; i <= n; i++)
        belt.push(i);
    
    int idx = 0;    // 어디까지 실었는지 체크
    while (idx < n) {
        // 벨트에서 하나 pop
        int q = belt.front();
        
        // 보조벨트에서 하나 pop
        int s = 0;
        if (help.size() != 0) 
            s = help.top();
        
        // 더이상 상자를 실을 수 없다.
        if (q > order[idx] && s > order[idx])
            break;
        
        // 벨트 -> 트럭
        if (q == order[idx]) {
            belt.pop();
            idx++;
            continue;
        }
        
        // 보조벨트 -> 트럭
        if (s == order[idx]) {
            help.pop();
            idx++;
            continue;
        }
        
        // 벨트 -> 보조
        belt.pop();
        help.push(q);
    }
    
    return idx;
}