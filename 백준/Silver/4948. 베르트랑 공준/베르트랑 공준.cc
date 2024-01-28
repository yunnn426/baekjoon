#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int arr[246950] = {0,};
    
    // 2부터 123,456 * 2까지 수 중 소수 구하기
    for (int i = 2; i <= sqrt(246912); i++) {
        if (arr[i] == 0) { // 소수의 배수는 소수가 아니다
            for (int j = 2; j * i <= 246912; j++) {
                arr[j * i] = 1;
            }
        }
    }
    
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (arr[i] == 0)
                cnt += 1;
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}

