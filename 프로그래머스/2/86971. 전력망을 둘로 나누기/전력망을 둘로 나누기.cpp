#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;




int solution(int n, vector<vector<int>> wires) {
    
    vector<int> visited(n + 1, 0);
    int answer = 1000;
    
    for (int ex = 0; ex < wires.size(); ex++) { // 하나씩 끊기
        vector<vector<int>> wire;
        for (int i = 0; i < wires.size(); i++) {
            if (i == ex) {
                continue;
            }
            wire.push_back(wires[i]);
        }
        fill(visited.begin(), visited.end(), 0);

        // 1번 송전탑부터 bfs
        vector<int> diffv;
        for (int i = 1; i <= n; i++) {
            if (visited[i] != 0) 
                continue;
            
            queue<int> q;
            visited[i] = 1;
            q.push(i);
            
            int tmp = 0;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                tmp += 1;
                for (int j = 0; j < wire.size(); j++) {
                    if (wire[j][0] == x) {
                        if (visited[wire[j][1]] != 0)
                            continue;
                        visited[wire[j][1]] = 1;
                        q.push(wire[j][1]);
                    }
                    else if (wire[j][1] == x) {
                        if (visited[wire[j][0]] != 0)
                            continue;
                        visited[wire[j][0]] = 1;
                        q.push(wire[j][0]);
                    }
                }
            }
            diffv.push_back(tmp);
        }
        
        int diff = abs(diffv[0] - diffv[1]);
        if (answer > diff) {
            answer = diff;
        }
    }
    
    return answer;
}