#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    long a, b, c;
    cin >> a >> b >> c;
    long answer = 1;
    
    while (b > 0) {
        if (b % 2 == 1) {
            answer = answer * a % c;
        }
        a = a * a % c;
        b /= 2;
    }
    
    cout << answer << "\n";
    
    return 0;
}
