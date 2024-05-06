#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    map<int, long long> cnt;
    int min_w = 1e9;
    int max_w = 0;
    for (auto w : weights) {
        cnt[w] += 1;
        min_w = min(min_w, w);
        max_w = max(max_w, w);
    }
    
    for (int i = min_w; i <= max_w; i++) {
        if (cnt[i] < 1) continue;
        long long cnt_w = cnt[i];
        
        if (i % 2 == 0) answer += cnt[i * 1 / 2] * cnt_w;
        if (i % 3 == 0) answer += cnt[i * 2 / 3] * cnt_w;
        if (i % 4 == 0) answer += cnt[i * 3 / 4] * cnt_w;
        answer += (cnt_w * (cnt_w - 1)) / 2;
    }
    
    return answer;
}