#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;
set<long> desc;

void dfs(long n) {
    if (n == 9876543210)
        return;
    for (int i = 0; i < (n % 10); i++) {
        //cout << "n: " << n << " i: " << i << endl;
        string s;
        s += to_string(n);
        s += to_string(i);
        desc.insert(stoul(s));
        dfs(stoul(s));
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    for (long i = 0; i <= 9; i++) {
        desc.insert(i);
        dfs(i);
    }
    
    auto iter = desc.begin();
    if (n > desc.size()) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        iter++;
    }
    cout << *iter << "\n";
    
    return 0;
}
