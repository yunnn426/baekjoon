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
        
        string cmp = subarr[0];
        int cnt = 1;
        for (int i = 1; i < subarr.size(); i++) {
            // 비교하는 문자열이랑 같으면 카운트 +1
            if (cmp == subarr[i]) {
                cnt += 1;
            }
            // 다르면
            else {
                // 문자열 길이만큼 더하고
                answer += cmp.length();
                // 2 이상인 경우 +길이
                if (cnt > 1)
                    answer += to_string(cnt).length();
                // 다시 초기화
                cnt = 1;
                cmp = subarr[i];
            }
        }
        
        ans = min(ans, answer);
    }
    return ans;
}