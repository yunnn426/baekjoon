#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int>> rect;
int iX, iY, answer = 987654321;
queue<tuple<int, int, int>> q; //  x, y, count
int visited[110][110] = {0,};

void find_adj(int x, int y, int cnt) {
    for (int i = 0; i < rect.size(); i++) {
        int x1 = rect[i][0]; int y1 = rect[i][1];
        int x2 = rect[i][2]; int y2 = rect[i][3];
        if (x1 <= x && x <= x2 && y1 <= y && y <= y2) { // 해당 직사각형에 포함되는 좌표인가 (내부, 둘레 포함)
            // 1. 왼쪽 세로변 위의 좌표
            if (x == x1) { 
                if (y == y1) { // 왼쪽 하단 꼭짓점
                    q.push(make_tuple(x, y + 1, cnt + 1));
                    q.push(make_tuple(x + 1, y, cnt + 1));
                }
                else if (y == y2) { // 왼쪽 상단 꼭짓점
                    q.push(make_tuple(x + 1, y, cnt + 1));
                    q.push(make_tuple(x, y - 1, cnt + 1));
                }
                else { // 직선 위 좌표 (꼭짓점 X)
                    q.push(make_tuple(x, y - 1, cnt + 1));
                    q.push(make_tuple(x, y + 1, cnt + 1));
                }
            }
            // 2. 오른쪽 세로변 좌표
            else if (x == x2) { 
                if (y == y1) { // 오른쪽 하단 꼭짓점
                    q.push(make_tuple(x, y + 1, cnt + 1));
                    q.push(make_tuple(x - 1, y, cnt + 1));
                }
                else if (y == y2) { // 오른쪽 상단 꼭짓점
                    q.push(make_tuple(x, y - 1, cnt + 1));
                    q.push(make_tuple(x - 1, y, cnt + 1));
                }
                else { // 직선 위 좌표 (꼭짓점 X)
                    q.push(make_tuple(x, y - 1, cnt + 1));
                    q.push(make_tuple(x, y + 1, cnt + 1));
                }
            }
            // 3. 가로변 좌표
            else if (y == y1 || y == y2) {
                q.push(make_tuple(x - 1, y, cnt + 1));
                q.push(make_tuple(x + 1, y, cnt + 1));
            }
        }
    }
}

bool is_inner(int x, int y) { // 직사각형 내부 좌표인가
    for (int i = 0; i < rect.size(); i++) {
        int x1 = rect[i][0]; int y1 = rect[i][1];
        int x2 = rect[i][2]; int y2 = rect[i][3];
        
        if (x1 < x && x < x2 && y1 < y && y < y2) {
            return true;
        }
    }
    return false;
}

void search() {
    
    while (!q.empty()) {
        
        int x = get<0>(q.front()); 
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        q.pop();
 
        if (visited[x][y] != 0)
            continue;
        if (is_inner(x, y))
            continue;
        
        visited[x][y] = 1;
        
        //cout << x << " " << y << " " << cnt << endl;
        
        // 종료 조건
        if (x == iX && y == iY) {
            answer = cnt;
            return;
        }
        
        find_adj(x, y, cnt);
        
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    iX = 2 * itemX;
    iY = 2 * itemY;
    // 한 변 길이가 1인 경우 경로가 끊길 수 있으므로 2배
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = 2 * rectangle[i][0]; int y1 = 2 * rectangle[i][1]; 
        int x2 = 2 * rectangle[i][2]; int y2 = 2 * rectangle[i][3]; 
        vector<int> tmp;
        tmp.push_back(x1); tmp.push_back(y1); tmp.push_back(x2); tmp.push_back(y2); 
        rect.push_back(tmp);
    }
    
    q.push(make_tuple(2 * characterX, 2 * characterY, 0));
    search();
    
    return answer / 2;
}