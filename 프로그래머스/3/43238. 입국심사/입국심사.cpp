#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(long long a, long long b) {
    return a > b;
}

long long solution(int nInt, vector<int> times) {
    sort(times.begin(), times.end(), desc);
    long long n = (long long)nInt;
    long long answer = 0;
    long long maxTime = n * (long long)times[0];
    long long end = maxTime;
    long long start = 1;
   
    while (start <= end) {
        long long mid = (start + end) / 2;
        //cout << start << " " << mid << " " << end << endl;
        long long cap = 0;
        for (int i = 0; i < (long long)times.size(); i++) {
            cap += (mid / (long long)times[i]);
            
            if (cap >= n) { // cap이 n 이상이면 정답 가능, 더 작은 정답 찾기 위해 결과 저장하고 계속 탐색 
                end = mid - 1;
                answer = mid;
                break;
            }
        }
        
        if (cap < n) {
            start = mid + 1;
        }
    }
    
    return answer;
}