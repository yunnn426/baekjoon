#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> sushi;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        sushi.push_back(n);
    }
    
    int max = 0, answer = 0;
    for (int i = 0; i < N; i++) {
        int check[30001] = {0,};
        int flag = 0, coupon = 1;
        for (int j = 0; j < k; j++) {
            if (i + j < N) {
                if (check[sushi[i + j]] == 1)
                    flag++;
                if (sushi[i + j] == c)
                    coupon = 0;
                check[sushi[i + j]] = 1;
            }
            else {
                if (check[sushi[i + j - N]] == 1)
                    flag++;
                if (sushi[i + j - N] == c)
                    coupon = 0;
                check[sushi[i + j - N]] = 1;
            }
        }
        answer = k - flag + coupon;
        if (answer > max)
            max = answer;
    }
    cout << max << "\n";

    return 0;
}