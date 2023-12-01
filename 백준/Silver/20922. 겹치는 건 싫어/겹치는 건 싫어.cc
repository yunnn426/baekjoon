#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int arr[200001] = {0,};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxl = 0, length = 0, i = 0, j = 0;
    int counter[100001] = {0,};
    while (j < n) {
        if (counter[arr[j]] == k) {
            counter[arr[i]]--;
            i++;
            length--;
        }
        else {
            counter[arr[j]]++;
            j++;
            length++;
        }
        maxl = max(maxl, length);
    }
    
    cout << maxl << "\n";
    return 0;
}