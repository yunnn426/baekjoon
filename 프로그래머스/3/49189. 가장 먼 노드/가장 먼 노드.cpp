#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> edges;
int node;
queue<pair<int, int>> q; // node - cnt
int visited[20010] = {0,};

int solution(int n, vector<vector<int>> edge) {
    edges = edge;
    node = n;
    int answer = 0, max_cnt = 0;
    q.push(make_pair(1, 0));
    visited[1] = 1;
    
    while (!q.empty()) {
        int nd = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt > max_cnt) {
            max_cnt = cnt;
            answer = 1;
        }
        else if (cnt == max_cnt) {
            answer += 1;
        }
        //cout << cnt << ": " << nd << endl;
        
        for (auto& iter : edge) {
            int a = iter[0];
            int b = iter[1];
            if (a == nd && visited[b] == 0) {
                visited[b] = 1;
                q.push(make_pair(b, cnt + 1));
            }
            if (b == nd && visited[a] == 0) {
                visited[a] = 1;
                q.push(make_pair(a, cnt + 1));
            }
        }
    }
    
    return answer;
}