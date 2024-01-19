#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


vector<string> split(string input, char dlim) {
    vector<string> result;
    
    stringstream ss;
    string stringBuffer;
    ss.str(input);
    
    while (getline(ss, stringBuffer, dlim)) {
        result.push_back(stringBuffer);
    }
    
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int n_gift[50][50] = {0,}; //주고받은 선물 표
    int rates[50][3] = {0,}; //선물지수
    
    //gifts를 2차원 배열로 
    for (int i = 0; i < gifts.size(); i++) {
        string s1 = gifts[i];
        vector<string> result = split(s1, ' ');
        
        int dx, dy;
        //1. 준사람 찾기
        for (int j = 0; j < friends.size(); j++) {
            if (friends[j] == result[0]) {
                dx = j;
            }
        }
        //2. 받은사람 찾기
        for (int j = 0; j < friends.size(); j++) {
            if (friends[j] == result[1]) {
                dy = j;
            }
        }
        n_gift[dx][dy] += 1;
        rates[dx][0] += 1;
        rates[dy][1] += 1;
    }
    
    //선물지수 계산
    for (int i = 0; i < 50; i++) {
        rates[i][2] = rates[i][0] - rates[i][1];
    }

    //정답 찾기
    //1. 서로 주고받으면 (한쪽이라도 0이 아니면) 덜 받은 쪽 +1
    //2. 서로 주고받은 적이 없으면 (둘다 0이면) 선물지수 높은 쪽 +1
    int answer[50] = {0,};
    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < friends.size(); j++) {
            if (i == j)
                continue;
            //1.
            if (n_gift[i][j] > n_gift[j][i]) {
                answer[i] += 1;
            }
            //2.
            else if (n_gift[i][j] == n_gift[j][i]) {
                if (rates[i][2] > rates[j][2]) {
                    answer[i] += 1;
                }
                else {
                    continue;
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < friends.size(); i++) {
        //cout << answer[i] << endl;
        if (answer[i] > ans)
            ans = answer[i];
    }
    
    return ans;
}