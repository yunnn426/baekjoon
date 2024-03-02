#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, answer = 0;
    cin >> n;
    for (int i = n; i > 0; i--) {
        int num = i;
        if (num % 5 == 0) {
            while (num > 1 && num % 5 == 0) {
                num /= 5;
                answer += 1;
            }
        }
    }
    
    cout << answer << "\n";

    return 0;
}
