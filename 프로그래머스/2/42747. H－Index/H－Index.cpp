#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for (int i = 0; i <= 1000; i++) { // 인용
        bool found = false;
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= i) {
                if (citations.size() - j >= i) {
                    //cout << i << " " << citations[j] - i << endl;
                    answer = i;
                    found = true;
                }
            }
        }
        if (!found)
            break;
    }
    
    return answer;
}