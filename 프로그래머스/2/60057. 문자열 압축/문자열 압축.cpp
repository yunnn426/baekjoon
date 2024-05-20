#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int n = s.length();
    int ans = n;
    
    for (int cut = 1; cut <= n / 2; cut++) {
        int answer = 0;
        /* cut만큼 잘라서 배열에 추가 */
        vector<string> subarr;
        int st = 0, ed = n - 1;
        
        while (st <= ed) {
            string sub = s.substr(st, cut);
            st += cut;
            subarr.push_back(sub);
        }
        subarr.push_back("end");
        
        string cmp = "";
        int cnt = 0;
        for (int i = 0; i < subarr.size(); i++) {
            if (cmp == "" || cmp != subarr[i]) {
                // 이전 문자열 처리
                if (cnt > 1)
                    answer += 1;
                cnt = 0;
                
                cmp = subarr[i];
                answer += cut;
                continue;
            }
            
            if (cmp == subarr[i]) {
                cnt += 1;
            }
        }
        
        ans = min(ans, answer);
    }
    return ans;
}