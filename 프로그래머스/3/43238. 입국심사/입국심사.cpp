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
        }
        if (cap > n) {
            end = mid - 1;     
        }
        else {
            start = mid + 1;
            answer = mid;
        }
    }
    
    while (true) {
        long long cap = 0;
        for (int i = 0; i < (long long)times.size(); i++) {
            cap += (answer / (long long)times[i]);
        }
        if (cap < n) {
            answer += 1;
            break;
        }
        answer -= 1;
    }
    
    return answer;
}