#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;

    bool nokey = true;
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (lock[i][j] == 0)
                nokey = false;
        }
    }
    if (nokey) return true; // key가 필요없음
    
    // lock 크기만큼 key를 확장
    int m = key.size();
    int n = lock.size();
    int len = 2 * n + m;
    vector<vector<int>> bigkey(len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i >= n && i < m + n) {
                if (j >= n && j < m + n) {
                    bigkey[i].push_back(key[i - n][j - n]);
                }
                else {
                    bigkey[i].push_back(0);
                }
            }
            else {
                bigkey[i].push_back(0);
            }
        }
    }
    
    // bigkey를 90도씩 돌리면서 lock이 들어갈 수 있는지 체크
    vector<vector<int>> newkey(len);
    newkey = bigkey;
    for (int angle = 0; angle < 4; angle++) {
        vector<vector<int>> cmpkey(len);
        int idx = 0;
        for (int t = 0; t < len; t++) {
            for (int i = len - 1; i >= 0; i--) {
                cmpkey[idx].push_back(newkey[i][idx]);
            }
            idx += 1;
        }
        newkey = cmpkey;
        
        for (int i = 0; i <= m + n; i++) {
            for (int j = 0; j <= m + n; j++) {
                bool found = true;
                
                for (int x = i; x < i + n; x++) {
                    for (int y = j; y < j + n; y++) {
                        if (newkey[x][y] + lock[x - i][y - j] != 1)
                            found = false;
                    }
                }
                
                if (found)
                    return true;
            }
        }
    }
    
    return false;
}