#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string s, t;
int answer = 0;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> s >> t;
    queue<string> q;
    q.push(t);
    string str = t;
    
    bool found = false;
    while (!q.empty()) {
        str = q.front();
        q.pop();

        if (str == s) {
            found = true;
            break;
        }
        if (str.length() < s.length())
            break;
        
        if (str[str.length() - 1] == 'A')
            q.push(str.substr(0, str.length() - 1));
        if (str[0] == 'B') {
            reverse(str.begin(), str.end());
            q.push(str.substr(0, str.length() - 1));
        }
    }
    
    if (found)
        cout << "1\n";
    else
        cout << "0\n";
    
    return 0;
}
