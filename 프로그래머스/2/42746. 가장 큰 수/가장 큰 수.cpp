#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    for(auto& iter : numbers) {
        if (answer == "0" && iter == 0)
            continue;
        answer += to_string(iter);
    }
    return answer;
}