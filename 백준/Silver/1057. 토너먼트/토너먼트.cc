#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, kim, lim, count = 0;
    cin >> n >> kim >> lim;
    
    bool hasmet = false;
    while (!hasmet) {
        int arr[100010] = {0,};
        int cnt = 0, team = 1;
        count += 1;
        
        for (int i = 0; i < n; i++) {
            if (cnt < pow(2, count)) {
                arr[i] = team;
                cnt += 1;
            }
            else {
                team += 1;
                arr[i] = team;
                cnt = 1;
            }
        }
        
        if (arr[kim - 1] == arr[lim - 1]) {
            hasmet = true;
        }
        
    }
    
    cout << count << "\n";
}

