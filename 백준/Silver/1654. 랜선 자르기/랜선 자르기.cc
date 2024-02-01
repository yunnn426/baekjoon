#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
vector<int> arr;

int countLan(long mid) {
    int tmp_n = 0;
    for (int i = 0; i < k; i++) {
        tmp_n += arr[i] / mid;
    }
    
    return tmp_n;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> k >> n;
    
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    // 제일 길이 짧은 랜선에서 구하는 길이 찾기
    sort(arr.begin(), arr.end());
    
    long s = 1;
    long e = arr[k - 1];
    long mid = (s + e) / 2;
    
    while (s <= e) {
        mid = (s + e) / 2;
        //cout << s << " " << mid << " " << e << endl;
        int tmp_n = countLan(mid);
        
        if (tmp_n < n) { // 길이 --
            e = mid - 1;
        }

        else {
            s = mid + 1;
        }
            
    }
    
    cout << e << "\n";
    
    return 0;
}

