#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int count = 0;
    while (N > 0) {
        N >= 3 ? N -= 3 : N -= 1;

        if (N == 0) {
            count % 2 == 0 ? cout << "SK\n" : cout << "CY";
        }
        
        count++;
    }

    return 0;
}