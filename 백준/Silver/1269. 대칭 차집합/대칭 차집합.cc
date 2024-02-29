#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<long> a;
    vector<long> b;
    for (int i = 0; i < n; i++) {
        long tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        long tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<long> result;
    result.resize(a.size() + b.size());
    auto iter = set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    result.erase(iter, result.end());

    cout << result.size() << "\n";
    
    return 0;
}
