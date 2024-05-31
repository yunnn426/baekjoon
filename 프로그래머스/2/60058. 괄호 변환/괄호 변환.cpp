#include <string>
#include <vector>
#include <stack>

using namespace std;

int find_uv(string str) {
    int len = str.length();
    int open = 0, close = 0, idx = 0;
    
    for (int i = 0; i < len; i++) {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
            close++;
        
        /* 균형잡힌 괄호 문자열을 찾은 경우 */
        if (open == close) {
            idx = i;
            break;
        }
    }
    
    return idx;     // 자를 곳의 인덱스 반환
}

bool is_correct(string str) {
    stack<char> s;
    int len = str.length();
    
    for (int i = 0; i < len; i++) {
        if (str[i] == '(')
            s.push('(');
        else if (str[i] == ')') {
            if (s.empty())
                return false;
            if (s.top() != '(')
                return false;
            s.pop();
        }
    }
    
    return true;
}

string convert(string str) {
    /* 1단계. 입력 문자열 == ""이면 바로 반환한다. */
    if (str == "")
        return "";

    /* 2단계. p를 u, v로 분리한다. */
    int i = find_uv(str);
    string u = str.substr(0, i + 1);
    string v = str.substr(i + 1);

    /* 3단계. u가 "올바른 괄호 문자열"이라면
        - v에 대해 1단계부터 다시 수행한 결과를
        - u에 붙여 반환한다. */
    if (is_correct(u)) {
        return u + convert(v);
    }

    /* 4단계. u가 "올바른 괄호 문자열"이 아니라면 */
    /* 4-1단계. 빈 문자열에 "("를 붙인다. */
    string blank = "(";
    
    /* 4-2단계. v에 대해 1단계부터 수행한 결과 문자열을 이어 붙인다. */
    blank += convert(v);
    
    /* 4-3단계. ")"를 붙인다. */
    blank += ")";
    
    /* 4-4단계. u의 처음과 마지막 문자를 제거하고,
                나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙인다. */
    int len = u.length();
    for (int i = 1; i < len - 1; i++) {
        if (u[i] == ')')
            blank += "(";
        if (u[i] == '(')
            blank += ")";
    }
    
    /* 4-5단계. 생성된 문자열을 반환한다. */
    return blank;
}

string solution(string p) {    
    if (p == "" || is_correct(p))
        return p;
    
    string answer = "";
    answer = convert(p);
    
    return answer;
}