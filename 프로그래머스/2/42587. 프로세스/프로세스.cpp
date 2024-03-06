#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    queue<int> job;
    for (int i = 0; i < priorities.size(); i++) {
        job.push(i);
    }
    
    while (!job.empty()) {
        int j = job.front();
        job.pop(); 
        int n = priorities[0];
        
        bool work = true;
        for (auto& iter : priorities) {
            if (iter > n) {
                work = false;
                break;
            }
        }
        
        priorities.erase(priorities.begin());
        if (work) {
            if (j == location)
                break;
            answer += 1;
        }
        else {
            priorities.push_back(n);
            job.push(j);
        }
    }
    
    return answer;
}