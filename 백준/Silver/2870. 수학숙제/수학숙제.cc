#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    int idx = 0;
    while (a[idx] == b[idx])
        idx++;
    return a[idx] < b[idx];
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<string> v;
    for (int t = 0; t < n; t++) {
        string s;
        cin >> s;
        s += "a";
        string tmp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                tmp += s[i];
            else {
                if (tmp == "")
                    continue;
                int idx = 0;
                while (tmp[idx] == '0')
                    idx += 1;
                if (idx >= tmp.length()) // Ex. 000
                    v.push_back("0");
                else
                    v.push_back(tmp.substr(idx));
                tmp = "";
            }
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    for (auto& iter : v) {
        cout << iter << "\n";
    }
    
    return 0;
}
