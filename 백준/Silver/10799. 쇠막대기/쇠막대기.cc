#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int answer = 0;
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push('(');
        }
        else {
            char before = s[i - 1];
            st.pop();
            if (before == '(') { // 레이저
                answer += st.size();
            }
            else { // 쇠막대기 끝
                answer += 1;
            }
        }
    }
    
    if (!s.empty()) {
        answer += st.size();
    }
    cout << answer << "\n";
    
    return 0;
}
