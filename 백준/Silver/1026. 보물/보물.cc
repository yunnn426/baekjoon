#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int a[55];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b[55];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    sort(a, a + n, desc);
    sort(b, b + n);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    cout << sum << "\n";

    return 0;
}

