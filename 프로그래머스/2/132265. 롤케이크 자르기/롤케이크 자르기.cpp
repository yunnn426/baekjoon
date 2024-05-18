#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m;
    
    // 토핑을 맵으로
    for (auto i : topping)
        m[i] += 1;    
    
    // 집합에 한 쪽 케이크 넣으면서 토핑 맵에서 하나씩 뺀다.
    set<int> s;
    
    int n = topping.size();
    for (int i = 0; i < n; i++) {
        s.insert(topping[i]);   // 집합에 넣고
        m[topping[i]] -= 1;     // 토핑에서 뺀다.
        
        if (m[topping[i]] == 0)     // value가 0이 되면 삭제
            m.erase(topping[i]);
        
        if (s.size() == m.size())  // 집합의 크기 == 토핑의 종류 개수
            answer += 1;
    }
    
    return answer;
}