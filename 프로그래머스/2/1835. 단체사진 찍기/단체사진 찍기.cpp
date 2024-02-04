#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> datas;
int visited[8] = {0,};
vector<int> line;
int answer = 0;

int get_idx(char c) {
    switch (c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'F':
            return 2;
        case 'J':
            return 3;
        case 'M':
            return 4;
        case 'N':
            return 5;
        case 'R':
            return 6;
        case 'T':
            return 7;
    }
}

bool check() {
    
    for (int i = 0; i < datas.size(); i++) {
        char a = datas[i][0];
        char b = datas[i][2];
        char op = datas[i][3];
        int dist = datas[i][4] - '0';
        //cout << a << " " << b << " " << op << " " << dist << endl;
        
        int idx_a = get_idx(a);
        int idx_b = get_idx(b);
        
        //cout << idx_a << " " << idx_b << endl;
        
        int pos_a = -1;
        int pos_b = -1;
        
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == idx_a) {
                pos_a = i;
            }
            
            if (line[i] == idx_b) {
                pos_b = i;
            }
        }
        
        int far = abs(pos_a - pos_b) - 1;

        switch (op) {
            case '=':
                if (far != dist) {
                    return false;
                }
                break;
            case '<':
                if (far >= dist) {
                    return false;
                }
                break;
            case '>':
                if (far <= dist) {
                    return false;
                }
                break;
        }
        
    }
    
    return true;
}

void dfs(int x) {
    if (x >= 8) {
        if (check() == true) {
            answer += 1;
        }
        return;
    }
    
    for (int i = 0; i < 8; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            line.push_back(i);
            dfs(x + 1);
            visited[i] = 0;
            line.pop_back();
        }
    }    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    datas = data;
    answer = 0;
    
    dfs(0);
    
    return answer;
}