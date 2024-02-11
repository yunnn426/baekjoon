#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> s;
int visited[15] = {0,};

void search(int n, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < k; i++) {
            if (visited[i] == 1) {
                cout << s[i] << " ";
            }
        }
        cout << "\n";
        return;
    }
    for (int i = n; i < k; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            search(i, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    while (true) {
        cin >> k;
        if (k == 0) break;
        
        s.clear();
        for (int i = 0; i < k; i++) {
            int tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        
        search(0, 0);
        cout << "\n";
    }
    
    return 0;
}

