#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    vector<int> v(26, 0);
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        int a = s[i];
        if (a < 97)
            a += 32;
        v[a - 97] += 1;
        cnt = max(cnt, v[a - 97]);
    }
    
    vector<int> many;
    for (int i = 0; i < 26; i++) {
        if (v[i] == cnt)
            many.push_back(i + 65);
    }
    
    if (many.size() != 1)
        cout << "?\n";
    else {
        char c = many[0];
        cout << c << "\n";
    }
        
    return 0;
}
