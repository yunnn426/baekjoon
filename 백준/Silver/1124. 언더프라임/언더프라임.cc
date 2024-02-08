#include <iostream>
#include <cmath>

using namespace std;

int a, b, answer = 0;
int dp[100010] = {0,};

void isUnderPrime(int n) {
    if (n == 1) return;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return;
        }
    }
    
    answer += 1;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> a >> b;
    
    dp[2] = 1;
    dp[3] = 1;
    
    // 4부터 b까지 수의 소인수분해 길이
    for (int i = 4; i <= b; i++) {
        int tmp = sqrt(i);
        bool isPrime = false;
        while (i % tmp != 0) {
            if (tmp == 2) {
                isPrime = true;
                break;
            }
            tmp -= 1;
        }
        if (isPrime) {
            dp[i] = 1;
        }
        else {
            dp[i] = dp[tmp] + dp[i / tmp];
        }
    }

    // a~b까지 언더프라임 구하기
    for (int i = a; i <= b; i++) {
        isUnderPrime(dp[i]);
    }
    cout << answer << "\n";
    
    return 0;
}

