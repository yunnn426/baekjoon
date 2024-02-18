#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.length() != 4 && s.length() != 6) {
        answer = false;
        return answer;
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 48 || s[i] > 57) { // 숫자가 아니면 
            answer = false;
            break;
        }
    }
    
    return answer;
}