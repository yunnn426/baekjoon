#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> pq;
    for (auto i : scoville) {
        pq.push(-1 * i); // 최소 힙
    }
    
    while (-1 * pq.top() < K) {
        if (pq.size() < 2) // 만들 수 없는 경우
            return -1;
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + b * 2;
        answer += 1;
        pq.push(c);
    }
    
    return answer;
}