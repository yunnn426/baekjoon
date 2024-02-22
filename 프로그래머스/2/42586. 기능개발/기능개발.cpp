#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    // 작업 일수 계산
    for (int i = 0; i < progresses.size(); i++) {
        int left = 100 - progresses[i];
        int day = left / speeds[i];;
        if (left % speeds[i] != 0) {
            day += 1;
        }
        q.push(day);
    }
    
    // 배포 횟수 계산
    while (!q.empty()) {
        int day = q.front();
        q.pop();
        int rls = 1;
        while (!q.empty()) {
            int d = q.front();
            if (d > day) // 뒷 작업이 더 오래걸리면 나중에 배포
                break;
            q.pop();
            rls += 1;
        }
        answer.push_back(rls);
    }
    
    return answer;
}