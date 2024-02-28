#include <iostream>
#include <vector>

using namespace std;

int n, m, lie_cnt;
vector<int> lie(55, 0);
vector<vector<int>> party; // 파티에서 진실을 아는 사람

void search(int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < party[i].size(); j++) {
            if (party[i][j] == n) { // 진실을 아는 사람이 파티에 존재하면
                // 그 파티에 있는 사람들도 진실을 앎
                for (int k = 0; k < party[i].size(); k++) {
                    if (j == k)
                        continue;
                    if (lie[party[i][k]] != 0) // 다른 파티에서 이미 진실을 안 경우 패스
                        continue;
                    lie[party[i][k]] += 1;
                    search(party[i][k]);
                }
            }
        }
    }
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    cin >> lie_cnt;
    for (int i = 0; i < lie_cnt; i++) {
        int tmp;
        cin >> tmp;
        lie[tmp] += 1;
    }
    
    if (lie_cnt == 0) { // 진실을 아는 사람이 없으면 다 거짓말 가능
        cout << m << "\n";
        return 0;
    }
    
    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;
        vector<int> v;
        for (int j = 0; j < cnt; j++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        party.push_back(v);
    }
    
    for (int i = 1; i < 55; i++) { // 진실을 알고 있는 사람 찾기
        if (lie[i] == 0)
            continue;
        search(i);
    }
    
    int answer = 0;
    for (int i = 0; i < party.size(); i++) {
        bool okay = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (lie[party[i][j]] != 0)
                okay = false;
        }
        if (okay)
            answer += 1;
    }
    cout << answer << "\n";
    
    return 0;
}
