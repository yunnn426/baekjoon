#include <iostream>

using namespace std;

int n;
int s;
int cnt = 0;
int arr[20];

void search(int k, int sum) {
    if (k == n) {
        if (sum == s)
            cnt += 1;
        return;
    }
    
    // 현재 원소 포함
    search(k + 1, sum + arr[k]);
    
    // 현재 원소 포함 x
    search(k + 1, sum);
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    search(0, 0);
    
    if (s == 0)
        cnt -= 1;
    
    cout << cnt << endl;
    
    return 0;
}

