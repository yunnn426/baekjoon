#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;
    int sums[250010];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        sums[i] = sum;
    }
    
    int maxv = 0, dur = 0;
    for (int i = x - 1; i < n; i++) {
        if (i == x - 1) {
            maxv = sums[i];
            dur = 1;
        }
        else {
            if (maxv < sums[i] - sums[i - x]) {
                maxv = sums[i] - sums[i - x];
                dur = 1;
            }
            else if (maxv == sums[i] - sums[i - x]) {
                dur += 1;
            }
        }
    }
    
    if (maxv == 0)
        cout << "SAD\n";
    else
        cout << maxv << "\n" << dur << "\n";
    
    return 0;
}
