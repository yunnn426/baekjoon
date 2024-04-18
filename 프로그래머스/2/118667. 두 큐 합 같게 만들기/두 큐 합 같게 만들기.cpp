#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    long sum1 = 0, sum2 = 0, dest = 0;
    queue<long> q1, q2;
    for (auto iter : queue1) {
        sum1 += iter;
        q1.push(iter);
    }
        
    for (auto iter : queue2){
        sum2 += iter;
        q2.push(iter);
    }
        
    if ((sum1 + sum2) % 2 == 1) // odd return -1
        return -1;
    else 
        dest = (sum1 + sum2) / 2;
    
    int cnt = 0;
    while (true) {
        // 목표 도달시 break
        if (sum1 == dest && sum2 == dest) {
            answer = cnt;
            break;
        }
        // 만들 수 없는 경우 break
        if (cnt > q1.size() + q2.size()) {
            answer = -1;
            break;
        }
        if (sum1 > sum2) {
            while (sum1 > dest) {
                long frn = q1.front();
                // q
                q1.pop();
                q2.push(frn);
                // cal sum
                sum1 -= frn;
                sum2 += frn;
                cnt += 1;
            }
        }
        
        else {
            while (sum2 > dest) {
                long frn = q2.front();
                // q
                q2.pop();
                q1.push(frn);
                // cal sum
                sum2 -= frn;
                sum1 += frn;
                cnt += 1;
            }
        }
    }
    
    
    return answer;
}