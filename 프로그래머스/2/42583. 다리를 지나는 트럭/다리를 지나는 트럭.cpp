#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> truck, bridge;
    for (auto& iter : truck_weights) {
        truck.push(iter);
    }
    
    int now = 0;
    for (int i = 0; i < bridge_length - 1; i++) {
        bridge.push(0);
    }
    
    while (!truck.empty()) {
        int tr = truck.front();
        if (now + tr <= weight) {
            truck.pop();
            now += tr;
            bridge.push(tr);
        }
        else {
            bridge.push(0);
        }
        
        int pp = bridge.front();
        now -= pp;
        bridge.pop();
        
        answer += 1;
    }
    answer += bridge_length;
    
    return answer;
}