#include <iostream>
#include <string>
#include <set>

using namespace std;

struct myOrder {
    bool operator() (const string &a, const string &b) const {
        if (a.size() == b.size()) {
            return a < b;
        }
        else {
            return a.size() < b.size();
        }
    }
};

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    set<string, myOrder> inputs;

    for (int tc = 0; tc < n; tc++) {
        string tmp;
        cin >> tmp;
        inputs.insert(tmp);
    }
    
    for (auto iter = inputs.begin(); iter != inputs.end(); iter++) {
        cout << *iter << endl;
    }

    
    return 0;
}

