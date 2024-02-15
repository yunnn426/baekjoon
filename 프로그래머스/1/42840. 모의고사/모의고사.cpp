#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int supo1[5] = {1, 2, 3, 4, 5};
    int supo2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int supo3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        int ans = answers[i];
        int idx1 = i % 5;
        int idx2 = i % 8;
        int idx3 = i % 10;
        
        if (ans == supo1[idx1]) {
            ans1 += 1;
        }
        if (ans == supo2[idx2]) {
            ans2 += 1;
        }
        if (ans == supo3[idx3]) {
            ans3 += 1;
        }
    }
    
    int n = max({ans1, ans2, ans3});
    if (n == ans1) {
        answer.push_back(1);
    }
    if (n == ans2) {
        answer.push_back(2);
    }
    if (n == ans3) {
        answer.push_back(3);
    }
    
    //cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return answer;
}