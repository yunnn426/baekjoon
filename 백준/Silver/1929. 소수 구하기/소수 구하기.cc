#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int m, n;
    cin >> m >> n;
    
    vector<bool> isPrime(1000010, true);
    isPrime[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        for (int j = 2; i * j <= n; j++) {
            isPrime[i * j] = false;
        }
    }
    
    for (int i = m; i <= n; i++) {
        if (isPrime[i])
            cout << i << "\n";
    }
    
    return 0;
}
