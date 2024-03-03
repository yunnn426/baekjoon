#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, n = nums.size() / 2;
    map<int, int> m;
    
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]] += 1;
    }
    
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > 0) {
            answer += 1;
        }
        if (answer == n) 
            break;
    }
    return answer;
}