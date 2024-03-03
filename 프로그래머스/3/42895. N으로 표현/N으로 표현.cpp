#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    
    int answer = -1;
    vector<set<int>> dp(10);
    
    for (int i = 1; i <= 8; i++) {
        int t = i, num = 0;
        while (t > 0) {
            num += N * pow(10, t - 1);
            t -= 1;
        }
        dp[i].insert(num);
    }
    
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j <= i - 1; j++) {
            for (auto& it1 : dp[j]) {
                for (auto& it2 : dp[i - j]) {
                    int num1 = it1 + it2;
                    int num2 = it1 - it2;
                    int num3 = it1 * it2;
                    int num4 = -1;
                    if (it2 != 0)
                        num4 = it1 / it2;
                    if (num1 >= 0 && num1 <= 32000) dp[i].insert(num1);
                    if (num2 >= 0 && num2 <= 32000) dp[i].insert(num2);
                    if (num3 >= 0 && num3 <= 32000) dp[i].insert(num3);
                    if (num4 >= 0 && num4 <= 32000) dp[i].insert(num4);
                }
            }
        }
    }
    
    for (int i = 1; i < dp.size(); i++) {
        bool found = false;
        for (auto& iter : dp[i]) {
            if (iter == number) {
                answer = i;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    
    return answer;
}