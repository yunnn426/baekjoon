#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int height[12] = {0,};
    int answer[12] = {0,};
    for (int i = 1; i <= n; i++) {
        cin >> height[i];
    }

    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp = height[i];
        for (int j = 1; j <= n; j++) {
            if (tmp == 0) {
                int count = 0;
                if (answer[j] != 0)
                    continue;
                answer[j + count] = i;
                break;
            }
            if (answer[j] == 0)
                tmp--;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}