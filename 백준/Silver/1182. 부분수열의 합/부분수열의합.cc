#include <iostream>

using namespace std;

int n, s;
int arr[25] = {0,};
int answer = 0;

void search(int x, int tmpsum) {
    if (x == n) {
        if (tmpsum == s) {
            answer += 1;
        }
        return;
    }
    
    search(x + 1, tmpsum);
    
    search(x + 1, tmpsum + arr[x]);
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
        
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    search(0, 0);
    
    if (s == 0) // 합이 0이면 부분수열이 공집합인 경우 제외
        answer -= 1;
    
    cout << answer << "\n";
    
    return 0;
}
