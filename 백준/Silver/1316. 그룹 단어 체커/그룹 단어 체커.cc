#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int alphabet[26] = {0,}; // 알파벳 쓰였는지 체크하는 배열
        bool isGroup = true;
        alphabet[s[0] - 97] += 1;
        for (int j = 1; j < s.size(); j++) {
            int idx = s[j] - 97;
            
            if (s[j] == s[j - 1]) {
                continue;
            }
            
            if (alphabet[idx] != 0) {
                //cout << s << " " << j << " " << s[j] << endl;
                isGroup = false;
                break;
            }
            
            alphabet[idx] += 1;
        }
        
        if (isGroup)
            answer += 1;
    }
    
    cout << answer << "\n";
    
    return 0;
}