#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), cmp);
    deque<int> dq;
    for (auto it : people)
        dq.push_back(it);
    
    // dq가 비어있지 않을 동안
    while (!dq.empty()) {
        answer += 1;                    // 보트 하나 만들고
        int tmp = dq.front();           // 가장 무거운 사람 추가
        dq.pop_front();
        
        if (dq.empty())
            break;
        
        int light = dq.back();          // 가장 가벼운 사람을 추가해보고
        if (tmp + light > limit)        // 태울 수 있는지 확인한다.
            continue;
        dq.pop_back();
    }
    
    return answer;
}