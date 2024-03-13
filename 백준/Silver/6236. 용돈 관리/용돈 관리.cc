#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> spend;
    int maxs = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        maxs = max(maxs, tmp);
        spend.push_back(tmp);
    }
    
    long start = maxs;
    long end = 10000000000;
    long answer = 0;
    while (start <= end) {
        long mid = (start + end) / 2;
        
        int refill = 1;
        long now = mid;
        for (int i = 0; i < spend.size(); i++) {
            if (now < spend[i]) {
                refill += 1;
                now = mid;
            }
            now -= spend[i];
        }
        
        if (refill > m) {
            start = mid + 1;
        }
        else {
            answer = mid;
            end = mid - 1;
        }
    }
    cout << answer << "\n";
    
    return 0;
}
