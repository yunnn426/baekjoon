#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int k, sum = 0;
    cin >> k;
    int arr[100000];
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] == 0) {
            int x = i - 1;
            while (arr[x] == 0) { //직전에 적은 수 찾기
                x--;
            }
            sum -= arr[x];
            arr[x] = 0;
        }
    }
    cout << sum << "\n";
    
    return 0;
}

