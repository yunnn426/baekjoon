#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int t, n;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        string p, arr;
        cin >> p;
        cin >> n;
        cin >> arr;
        
        deque<int> dq;
        arr = arr.substr(1);
        string s = "";
        for (int i = 0; i < arr.length(); i++) {
            if (arr[i] == ',' || arr[i] == ']') {
                if (i - 1 >= 0)
                    dq.push_back(stoi(s));
                s = "";
            }
            else {
                s += arr[i];
            }
        }
        
        // 함수 수행
        bool error = false;
        int cntr = 0;
        char menu = NULL;
        for (int i = 0; i < p.length(); i++) {
            if (error)
                break;
            if (p[i] == 'R') {
                cntr += 1;
                if (cntr % 2 == 0)
                    menu = NULL;
                else
                    menu = 'R';
            }
            else {
                switch (menu) {
                    case 'R':
                        if (dq.size() != 0)
                            dq.pop_back();
                        else
                            error = true;
                        break;
                    case NULL:
                        if (dq.size() != 0)
                            dq.pop_front();
                        else
                            error = true;
                        break;
                    default:
                        break;
                }
            }
        }
        
        if (error)
            cout << "error\n";
        else {
            cout << "[";
            if (cntr % 2 != 0)
                reverse(dq.begin(), dq.end());
            for (int j = 0; j < dq.size(); j++) {
                if (j != dq.size() - 1)
                    cout << dq[j] << ",";
                else
                    cout << dq[j];
            }
            cout << "]\n";
        }
    }
    
    return 0;
}
