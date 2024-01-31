#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool longer(string a, string b) {
    if (a.size() == b.size())
        return a < b;
    else
        return a.size() < b.size();
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    set<string> inputs;
    vector<string> answer;
    
    for (int tc = 0; tc < n; tc++) {
        string tmp;
        cin >> tmp;
        inputs.insert(tmp);
    }
    
    for (auto iter = inputs.begin(); iter != inputs.end(); iter++) {
        answer.push_back(*iter);
    }
    
    sort(answer.begin(), answer.end(), longer);
    
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << "\n";
    }
    
    return 0;
}

