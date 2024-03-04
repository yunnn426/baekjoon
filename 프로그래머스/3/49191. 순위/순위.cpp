#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int league[105][105] = {0,};
    
    for (int i = 0; i < results.size(); i++) {
        int a = results[i][0];
        int b = results[i][1];
        league[a][b] = 1;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (league[i][k] == 1 && league[k][j] == 1) {
                    league[i][j] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int win = 0, lose = 0;
        // win
        for (int j = 1; j <= n; j++) {
            if (league[i][j] == 1)
                win += 1;
        }
        
        // lose
        for (int j = 1; j <= n; j++) {
            if (league[j][i] == 1)
                lose += 1;
        }
        
        if (lose + win == n - 1)
            answer += 1;
    }
    
    return answer;
}