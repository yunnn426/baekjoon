#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> bracket;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            bracket.push('(');
        }
        else {
            if (bracket.size() == 0) { // 꺼낼게 없으면
                answer = false;
                break;
            }
            char c = bracket.top();
            if (c != '(') { // 짝이 안 맞으면
                answer = false;
                break;
            }
            bracket.pop();
        }
    }
    
    if (bracket.size() != 0) { // 스택 아직 남아있으면
        answer = false;
    }

    return answer;
}