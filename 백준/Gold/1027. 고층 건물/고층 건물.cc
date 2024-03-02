#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, answer = 0;
vector<int> v;
int see[55] = {0,};

bool checkHeight(int i, int j) {
    double a = v[i];
    double b = v[j];
    double k = abs(a - b) / (j - i);
    if (a > b)
        k *= -1;
    int idx = 1;
    
    for (int x = i + 1; x < j; x++) {
        double diff = a + (k * idx);
        if (v[x] >= diff)
            return false;
        idx += 1;
    }
    return true;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) continue;
            if (abs(i - j) == 1) { // 바로 옆 건물
                see[i] += 1;
                see[j] += 1;
            }
            else {
                if (checkHeight(i, j)) {
                    see[i] += 1;
                    see[j] += 1;
                }
            }
        }
    }
    
    sort(see, see + n);
    cout << see[n - 1] << "\n";
    
    return 0;
}
