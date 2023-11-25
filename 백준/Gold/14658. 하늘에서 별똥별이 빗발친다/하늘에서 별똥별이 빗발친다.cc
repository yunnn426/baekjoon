#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N, M, L, K;
    cin >> N >> M >> L >> K;
    int stars[101][2];
    for (int i = 0; i < K; i++) {
        cin >> stars[i][0] >> stars[i][1];
    }

    int max_in = 0; //트램펄린에 포함되는 최대 별똥별 수
    for (int i = 0; i < K; i++) { 
        for (int j = 0; j < K; j++) { //i번째 별 x, j번째 별 y를 꼭지점으로 하는 트램펄린
            int count = 0;
            for (int s = 0; s < K; s++) {
                if (stars[i][0] <= stars[s][0] && stars[s][0] <= stars[i][0] + L)
                    if (stars[j][1] <= stars[s][1] && stars[s][1] <= stars[j][1] + L)
                        count++;
            }
            max_in = max(count, max_in);
        }
    }

    cout << K - max_in << "\n";

    return 0;
}