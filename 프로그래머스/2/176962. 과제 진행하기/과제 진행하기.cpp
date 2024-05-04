#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<int> start_time;
    sort(plans.begin(), plans.end(), cmp); // 시작 시간 순으로 정렬
    
    int min_start = 23 * 60 + 60;
    for (int i = 0; i < plans.size(); i++) {
        string start = plans[i][1];
        int start_min = 60 * stoi(start.substr(0, 2)) + stoi(start.substr(3, 2)); // 시작 시간을 분으로 변환
        start_time.push_back(start_min);
        min_start = min(min_start, start_min);
    }
    
    int job_idx = -1;
    bool done = false;
    for (int t = min_start; t <= 23 * 60 + 59 + 100000; t++) {
        for (int i = 0; i < plans.size(); i++) {
            string start = plans[i][1];
            string time = plans[i][2];
                
            if (start_time[i] == t) {
                done = false;
                job_idx = i;
                break;
            }
            if (done && stoi(time) > 0 && start_time[i] < t) {
                job_idx = i;
                // cout << "이전 작업: " << plans[job_idx][0] << endl;
            }
        }
        
        int left_time = stoi(plans[job_idx][2]) - 1;
        if (left_time < 0) continue; 
        // cout << "time: " << t << ", doing: " << plans[job_idx][0] << ", left time: " << left_time << endl;
        
        if (left_time == 0) {
            done = true;
            answer.push_back(plans[job_idx][0]);
        }
        plans[job_idx][2] = to_string(left_time); // 남은 시간 갱신
    }
    
    return answer;
}