#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.length();
    if (n % 2 != 0) return 0;
    
    for (int i = 0; i < n; i++) {
        // 회전한 문자열
        string rotate = s.substr(i) + s.substr(0, i);
        bool correct = true;
        
        stack<char> st;
        for (int j = 0; j < rotate.size(); j++) {
            // 여는 괄호 푸시
            if (rotate[j] == '{' || rotate[j] == '[' || rotate[j] == '(') {
                st.push(rotate[j]);
            }
            // 닫는 괄호 팝
            else {
                if (st.empty()) {   // 짝이 없다
                    correct = false;
                    break;
                }
                
                char c = st.top();  // 하나 팝해서 짝 비교 시작
                st.pop();
                char ans;           // 올바른 짝
                if (rotate[j] == '}')
                    ans = '{';
                else if (rotate[j] == ']')
                    ans = '[';
                else if (rotate[j] == ')')
                    ans = '(';
                if (ans != c) {
                    correct = false;
                    break;
                }
            }
        }
        
        if (correct)
            answer += 1;
    }
    
    return answer;
}