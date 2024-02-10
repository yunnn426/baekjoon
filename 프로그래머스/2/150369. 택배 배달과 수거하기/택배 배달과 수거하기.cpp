#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d_cap = 0;
    int p_cap = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 0;
        
        while (d_cap < deliveries[i] || p_cap < pickups[i]) {
            cnt += 1;
            d_cap += cap;
            p_cap += cap;
        }
        d_cap -= deliveries[i];
        p_cap -= pickups[i];
        
        answer += (long long)(i + 1) * cnt * 2;
    }
    
    return answer;
}