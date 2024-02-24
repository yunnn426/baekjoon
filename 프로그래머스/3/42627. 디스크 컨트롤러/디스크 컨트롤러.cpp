#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int n = jobs.size();
    
    // 해당 시간에 처리 가능한 작업 중 소요시간이 가장 짧은 것 선택
    while (jobs.size() != 0) {
        int now_job = -1; // 이번 시간에 처리할 작업의 인덱스
        int request = 0;
        int duration = 1001; // 이번 시간에 처리할 작업의 소요시간
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] <= time) {
                if (jobs[i][1] < duration) {
                    now_job = i;
                    request = jobs[i][0];
                    duration = jobs[i][1];
                }
            }
        }
        if (now_job == -1) { // 처리할 작업이 없으면 다음 시간으로
            time += 1;
            continue;
        }
        jobs.erase(jobs.begin() + now_job);
        answer += (time - request) + duration;
        //cout << "time: " << time << ", ans: " << answer << endl;
        time += duration;
    }
    
    return answer / n;
}