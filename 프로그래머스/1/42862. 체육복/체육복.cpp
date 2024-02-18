#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    answer = n - lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 여벌 체육복을 가져온 학생이 체육복을 도난당함
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                reserve[j] = -1;
                lost[i] = -1;
                answer += 1;
                break;
            }
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == -1)
            continue;
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == -1)
                continue;
            if (lost[i] == (reserve[j] - 1) || lost[i] == reserve[j] || lost[i] == (reserve[j] + 1)) {
                reserve[j] = -1;
                answer += 1;
                break;
            }
        }
    }
    return answer;
}