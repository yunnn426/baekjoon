#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dist = true;
vector<vector<string>> place;

bool checkPartition(int t, int x, int y, int a, int b) {
    if (abs(x - a) + abs(y - b) > 2) // 맨해튼거리 2 초과: o
        return true;
    if (abs(x - a) + abs(y - b) == 1) // 바로 옆자리: x
        return false;
    int minx = min(x, a); int maxx = max(x, a);
    int miny = min(y, b); int maxy = max(y, b);
    for (int i = minx; i <= maxx; i++) {
        for (int j = miny; j <= maxy; j++) {
            if (place[t][i][j] == 'O') // 파티션으로 나눠져있지 않은 경우
                return false;
        }
    }
    return true;
}

void search(int t, int x, int y) {
    for (int i = x - 2; i <= x + 2; i++) {
        if (i < 0 || i >= 5)
            continue;
        for (int j = y - 2; j <= y + 2; j++) {
            if (j < 0 || j >= 5)
                continue;
            if (place[t][i][j] != 'P') 
                continue;
            if (!checkPartition(t, x, y, i, j))
                dist = false;
            if (!dist)
                return;
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    place = places;
    
    for (int t = 0; t < places.size(); t++) {
        dist = true;
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (places[t][i][j] != 'P') 
                    continue;
                search(t, i, j);
                if (!dist)
                    break;
            }
            if (!dist)
                break;
        }
        
        if (dist)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}