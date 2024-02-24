#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        string s;
        cin >> s;
        stack<char> st;
        bool vps = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push('(');
            }
            else {
                if (st.empty()) {
                    vps = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty())
            vps = false;
        
        if (vps)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
