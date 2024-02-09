#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, stu;
    cin >> n;
    int switches[105];
    for (int i = 1; i <= n; i++) {
        cin >> switches[i];
    }
    cin >> stu;
    for (int i = 0; i < stu; i++) {
        int sex, num;
        cin >> sex >> num;
        if (sex == 1) { // 남
            for (int j = 1; num * j <= n; j++) {
                switches[num * j] = abs(switches[num * j] - 1);
            }
        }
        else { // 여
            int a = num - 1;
            int b = num + 1;
            while (true) {
                if ((switches[a] != switches[b]) || a < 1 || b > n) {
                    for (int j = a + 1; j < b; j++) {
                        switches[j] = abs(switches[j] - 1);
                    }
                    break;
                }
                a -= 1;
                b += 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << switches[i];
        if (i != n && i % 20 != 0) {
            cout << " ";
        }
        if (i % 20 == 0 && i != 1) {
            cout << "\n";
        }
    }
    cout << "\n";
    
    return 0;
}
