#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, answer = 0;

void z(int n, int r, int c) {
    
    if (n == 1) { // 2 * 2만 남았을때
        //cout << "r: " << r << " c: " << c << endl;
        if (r == 0 && c == 0) {
            answer += 0;
        }
        else if (r == 0 && c == 1) {
            answer += 1;
        }
        else if (r == 1 && c == 0) {
            answer += 2;
        }
        else {
            answer += 3;
        }
        return;
    }
        
    
    int l = pow(2, n - 1); // board 길이 / 2
    int newc = c % l; // 4등분한 새로운 r & c
    int newr = r % l;
    
    // 1사분면
    if (r < l && c >= l) {
        //cout << "1사" << " r: " << r << " c: " << c << endl;
        answer += 1 * pow(4, n - 1); // 해당 사분면의 (0,0) 위치의 값 +
        z(n - 1, r, newc);
    }
    // 2사분면
    else if (r < l && c < l) {
        //cout << "2사" << " r: " << r << " c: " << c << endl;
        answer += 0 * pow(4, n - 1);
        z(n - 1, r, c);
    }
    // 3사분면
    else if (r >= l && c < l) {
        //cout << "3사" << " r: " << r << " c: " << c << endl;
        answer += 2 * pow(4, n - 1);
        z(n - 1, newr, c);
    }
    // 4사분면
    else {
        //cout << "4사" << " r: " << r << " c: " << c << endl;
        answer += 3 * pow(4, n - 1);
        z(n - 1, newr, newc);
    }
    
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> r >> c;
    
    z(n, r, c);
    
    cout << answer << "\n";
    return 0;
}

