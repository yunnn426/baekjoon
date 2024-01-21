#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
    int mid;
    while (s <= e) {
        mid = (s + e) / 2;
        
        if (key == arr[mid])
            return 1;
        else if (key > arr[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return 0;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, mid, e;
        s = 0; e = n; mid = (s + e) / 2;
        
        int tmp, ans;
        cin >> tmp;
        
        ans = binarySearch(a, s, e, tmp);
        cout << ans << "\n";
    }
    
    return 0;
}

