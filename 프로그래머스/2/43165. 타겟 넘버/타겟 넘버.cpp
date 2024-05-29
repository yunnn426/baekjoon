#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0, dst, n;
vector<int> number;

void search(int idx, int sum) {
    if (idx == n) {
        if (sum == dst) 
            answer += 1;
        return;
    }
    
    search(idx + 1, sum + number[idx]);
    search(idx + 1, sum - number[idx]);
}

int solution(vector<int> numbers, int target) {
    number = numbers;
    dst = target;
    n = numbers.size();
    
    search(0, 0);
    
    return answer;
}