#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> height;
    list<int> answer;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        height.push_back(tmp);
    }
    
    
    for (int i = n - 1; i >= 0; i--) {
        auto iter = answer.begin();
        for (int j = 0; j < height[i]; j++) {
            iter++;
        }
        answer.insert(iter, i + 1);
    }
    
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
    
    return 0;
}

