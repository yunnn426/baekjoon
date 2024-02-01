#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int l;
    cin >> l;
    vector<int> arr;
    for (int i = 0; i < l; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    sort(arr.begin(), arr.end());
    
    int n;
    int a = 0;
    int b = arr.back();
    cin >> n;
    for (int i = 1; i < l; i++) {
        if (arr[i - 1] <= n && n <= arr[i]) {
            a = arr[i - 1];
            b = arr[i];
            break;
        }
        if (n <= arr[0]) {
            b = arr[i - 1];
            break;
        }
    }
    //cout << "a, b: " << a << " " << b << endl;
    
    int answer = 0;
    if (a == n || b == n) {
        answer = 0;
    }
    else {
        for (int i = a + 1; i <= n; i++) {
            for (int j = n; j < b; j++) {
                if (i == j)
                    continue;
                //cout << i << " " << j << endl;
                answer += 1;
            }
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
