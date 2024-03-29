#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int arr[1000010];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}
