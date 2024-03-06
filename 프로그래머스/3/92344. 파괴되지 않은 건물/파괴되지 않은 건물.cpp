#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int sum[1005][1005] = {0,}; // 누적합 배열
    
    for (int t = 0; t < skill.size(); t++) {
        int type = skill[t][0];
        int r1 = skill[t][1];
        int c1 = skill[t][2];
        int r2 = skill[t][3];
        int c2 = skill[t][4];
        int degree = skill[t][5];
        if (type == 1)
            degree *= -1;
        
        /*
        n 0 0 -n            n n n 0
        0 0 0 0     누적합    n n n 0
        0 0 0 0     ->      n n n 0
        -n 0 0 n            0 0 0 0
        */
        sum[r1][c1] += degree;
        sum[r2 + 1][c2 + 1] += degree;
        sum[r1][c2 + 1] -= degree;
        sum[r2 + 1][c1] -= degree;
    }
    
    for (int i = 0; i < board.size(); i++) {
        // 왼->오 누적합
        for (int j = 1; j < board[0].size(); j++) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    for (int i = 0; i < board[0].size(); i++) {
        // 위->아래 누적합
        for (int j = 1; j < board.size(); j++) {
            sum[j][i] += sum[j - 1][i];
        }
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            board[i][j] += sum[i][j];
            if (board[i][j] > 0)
                answer += 1;
        }
    }
    return answer;
}