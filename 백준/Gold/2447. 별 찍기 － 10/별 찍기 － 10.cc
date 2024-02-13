#include <iostream>

using namespace std;

int n;

void star(int x, int y, int k) {
    if ((x / k) % 3 == 1 && (y / k) % 3 == 1) {
        cout << " ";
    }
    else {
        if (k == 1) {
            cout << "*";
        }
        else {
            star(x, y, k / 3);
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            star(i, j, n);
        }
        cout << "\n";
    }
    
    return 0;
}

