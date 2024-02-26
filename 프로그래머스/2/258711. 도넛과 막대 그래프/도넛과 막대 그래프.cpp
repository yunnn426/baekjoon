#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    vector<int> v(2, 0);
    vector<vector<int>> in_out(1000010, v); // 정점 별 in, out 간선
    int num = 0; // 마지막 노드 번호
    
    for (int i = 0; i < edges.size(); i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        in_out[x][1] += 1;
        in_out[y][0] += 1;
        if (num < x)
            num = x;
        if (num < y)
            num = y;
    }
    
    int c_edge = 0, c_cnt = 0;
    int donut = 0, bar = 0, eight = 0;
    
    for (int i = 1; i <= num; i++) {
        int in = in_out[i][0];
        int out = in_out[i][1];
        
        if (in == 0 && out >= 2) { // 들어오는 간선 0, 나가는 간선 2 이상이면 생성된 정점
            c_edge = i;
            c_cnt = out;
        }
        else if (out == 2) // 나가는 간선이 2개이면 8자 그래프
            eight += 1;
        else if (out == 0) // 나가는 간선이 없으면 막대 그래프
            bar += 1;
        
    }
    
    donut = c_cnt - eight - bar; // 생성된 정점의 나가는 간선 수 == 전체 그래프 수
    answer.push_back(c_edge);
    answer.push_back(donut);
    answer.push_back(bar);
    answer.push_back(eight);
    
    return answer;
}