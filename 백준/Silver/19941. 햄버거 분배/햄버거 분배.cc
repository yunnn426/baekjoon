#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    char table[N];
    for (int i = 0; i < N; i++) {
        cin >> table[i];
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (table[i] == 'H')
            continue;
        
        if (table[i] == 'N') // 있던 햄버거 먹음 
            continue;

        // 0 ~ K    
        if (i < K) {
            for (int j = 0; j <= i + K; j++) {
                if (table[j] == 'H') {
                    answer++;
                    table[j] = 'N';
                    break;
                }
            }
        }

        // N-K ~ K
        else if (i >= N - K) {
            for (int j = i - K; j < N; j++) {
                if (table[j] == 'H') {
                    answer++;
                    table[j] = 'N';
                    break;
                }
            }
        }

        else {
            for (int j = i - K; j <= i + K; j++) {
                if (table[j] == 'H') {
                    answer++;
                    table[j] = 'N';
                    break;
            }
            }
        }
    }

    cout << answer << endl;

	return 0;
}