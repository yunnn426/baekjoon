#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int h, w;
    cin >> h >> w;
    int block[501];
    for (int i = 0; i < w; i++) {
        cin >> block[i];
    }

    int answer = 0;
    for (int i = 1; i < w - 1; i++) {
        int lmax = 0, rmax = 0;
        for (int j = 0; j < w; j++) {
            if (j < i) { // 왼쪽 검사
                if (block[j] > lmax) 
                    lmax = block[j];
            }
            else if (j > i) { // 오른쪽 검사
                if (block[j] > rmax) {
                    rmax = block[j];
                }
            }
        }
        if (block[i] < min(lmax, rmax)) {
            int rain = min(lmax, rmax) - block[i]; // 좌우에 존재하는 가장 높은 블록 중 작은 값
            answer += rain;
            //cout << rain << endl;
        }
    }

    cout << answer << "\n";

    return 0;
}