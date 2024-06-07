#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> computer;
int n; 
int visited[205] = {0,};

void dfs(int from) {
    for (int to = 0; to < n; to++) {
        if (visited[to] != 0)
            continue;
        if (computer[from][to] == 0)
            continue;
        
        visited[to] = 1;
        dfs(to);
    }
}

int solution(int m, vector<vector<int>> computers) {
    n = m;
    computer = computers;
    
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (visited[i] != 0)
            continue;
        
        answer += 1;
        visited[i] = 1;
        dfs(i);
    }
    
    return answer;
}