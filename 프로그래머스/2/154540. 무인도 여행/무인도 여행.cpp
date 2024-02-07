#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> map;
vector<int> answer;
int map_v[105][105] = {0,};
int visited[105][105] = {0,};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = 0;

void search(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ((0 <= nx && nx < map.size()) && (0 <= ny && ny < map[0].length())) {
            if (map_v[nx][ny] != 0 && visited[nx][ny] == 0) {
            visited[nx][ny] = 1;
            ans += map_v[nx][ny];
            search(nx, ny);
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    map = maps;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].length(); j++) {
            int val;
            char c_val = maps[i][j];
            if (c_val == 'X') {
                val = 0;
            }
            else {
                val = c_val - '0';
            }
            map_v[i][j] = val;
        }
    }
    
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].length(); j++) {
            if (map_v[i][j] != 0 && visited[i][j] == 0) {
                ans += map_v[i][j];
                visited[i][j] = 1;
                search(i, j);
                answer.push_back(ans);
                ans = 0;
            }
        }
    }
    
    if (answer.size() == 0) {
        answer.push_back(-1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}