#include <iostream>

using namespace std;

int numbers[2001];
int palin[2001][2001] = { 0, };

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < N; i++) { //길이 1
        palin[i][i] = 1;
    }

    for (int i = 0; i < N - 1; i++) { // 길이 2
        if (numbers[i] == numbers[i + 1])
            palin[i][i + 1] = 1;
    }

    for (int len = 3; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            if (numbers[i] == numbers[j] && palin[i + 1][j - 1]) {
                palin[i][j] = true;
            }
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;

        cout << palin[S - 1][E - 1] << "\n";
    }

    return 0;
}