#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int x = want.size(), y = discount.size();
    // want를 맵에 매핑
    map<string, int> m;
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] += number[i];
    }
    
    // int n = 0;
    // for (auto i : m) {
    //     cout << want[n] << endl;
    //     n++;
    //     cout << i.first << " " << i.second << endl;
    // }
    
    int sum_table[15][100005] = {0,};
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int tmp = 0;
            for (int k = 0; k < 10; k++) {
                if (j + k > y) break;
                if (want[i] == discount[j + k])
                    tmp += 1;
            sum_table[i][j] = tmp;
            }
        }
    }
    
    // for (int i = 0; i < x; i++) {
    //     for (int j = 0; j < y; j++) {
    //         cout << sum_table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for (int j = 0; j < y; j++) {
        bool okay = true;
        for (int i = 0; i < x; i++) {
            // cout << want[i] << ": " << sum_table[i][j] << " / " << m[want[i]] << endl;
            if (sum_table[i][j] < m[want[i]]) {
                okay = false;
                break;
            }
        }
        cout << endl;
        
        if (okay) answer += 1;
    }
    
    return answer;
}