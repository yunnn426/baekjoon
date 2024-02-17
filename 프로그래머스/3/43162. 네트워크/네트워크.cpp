#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0, total;
vector<vector<int>> computer;
int visited[205] = {0,};

void search(int cnt, int x) {
    if (cnt == total) {
        return;
    }
    for (int i = 0; i < computer[x].size(); i++) {
       if (visited[i] != 0) 
           continue;
        if (computer[x][i] == 1) {
            visited[i] = 1;
            //cout << "\t" << x << " connected to " << i << endl;
            search(cnt + 1, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    total = n;
    computer = computers;
    
    for (int i = 0; i < computers.size(); i++) {
        if (visited[i] != 0)
            continue;
        visited[i] = 1;
        answer += 1;
        //cout << "visit " << i << endl;
        search(1, i);
    }
    
    return answer;
}