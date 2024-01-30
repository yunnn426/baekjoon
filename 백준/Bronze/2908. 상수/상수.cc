#include <iostream>

using namespace std;

int sangsu(int n) {
    int newn = 0;
    newn += n % 10 * 100;
    newn += n % 100 / 10 * 10;
    newn += n / 100;
    
    return newn;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n1, n2;
    cin >> n1 >> n2;
    
    int new1 = sangsu(n1);
    int new2 = sangsu(n2);
    int answer = max(new1, new2);
    cout << answer << "\n";
    
    return 0;
}
