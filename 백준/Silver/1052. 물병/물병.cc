#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, k, answer = 0;
    cin >> n >> k;

    while (true) {
        int cnt = 0;
        string s = bitset<25>(n).to_string();
        
        for (int i = 0; i < 25; i++) {
            if (s[i] != '0')
                cnt += 1;
        }
        
        if (cnt <= k)
            break;
        else {
            answer += 1;
            n += 1;
        }
    }
    cout << answer << "\n";
    
    return 0;
}
