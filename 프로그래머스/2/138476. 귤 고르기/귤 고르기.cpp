#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0, count = 0;
    map<int, int> cnt;
    
    for (auto t : tangerine) {
        cnt[t] += 1;
    }
    
    vector<pair<int, int>> v(cnt.begin(), cnt.end());
    sort(v.begin(), v.end(), cmp); // 개수 기준 정렬

    for (auto it : v) {
        if (count < k) {
            count += it.second;
            answer += 1;
        }
    }
    
    return answer;
}