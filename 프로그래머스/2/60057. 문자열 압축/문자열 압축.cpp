#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> results;
    
    for (int unit = 1; unit <= s.length(); unit++) {
        queue<string> cut;
        int idx = 0;
        while (true) {
            string ss = s.substr(idx, unit);
            cut.push(ss);
            if (idx + unit >= s.length()) {
                break;
            }
            idx = idx + unit;
        }
        
        string zip_s = "";
        while (!cut.empty()) {
            string a = cut.front();
            cut.pop();
            int cnt = 1;
            while (!cut.empty()) {
                string cmp = cut.front();
                if (cmp == a) {
                    cnt += 1;
                    cut.pop();
                }
                else {
                    break;
                }
            }
            if (cnt != 1)
                zip_s += to_string(cnt);
            zip_s += a;
        }
        
        results.push_back(zip_s.length());
    }
    
    sort(results.begin(), results.end());
    answer = results[0];
    
    return answer;
}