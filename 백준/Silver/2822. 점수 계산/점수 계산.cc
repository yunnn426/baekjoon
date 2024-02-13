#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    vector<pair<int, int>> score; // (문제번호 - 점수)
    for (int i = 0; i < 8; i++) {
        int q = i + 1;
        int scr;
        cin >> scr;
        score.push_back(make_pair(q, scr));
    }
    
    sort(score.begin(), score.end(), desc);
    
    int sum = 0;
    vector<int> qt;
    for (int i = 0; i < 5; i++) {
        sum += score[i].second;
        qt.push_back(score[i].first);
    }
    cout << sum << "\n";
    
    sort(qt.begin(), qt.end());
    for (int i = 0; i < 5; i++) {
        cout << qt[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
