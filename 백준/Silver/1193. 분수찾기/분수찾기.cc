#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int x;
    cin >> x;
    
    int idx, sum = 0, d = 0;
    for (int i = 0; sum < x; i++) {
        sum += i;
        idx = i;
        d = x - sum;
    }
    
    int a, b; // a / b
    if (idx % 2 == 0) {
        b = -1 * d + 1;
        a = idx + 1 - b;
    }
    else {
        a = -1 * d + 1;
        b = idx + 1 - a;
    }
    
    cout << a << "/" << b << "\n";
    return 0;
}
