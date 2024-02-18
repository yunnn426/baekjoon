#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int now, answer = 0;
vector<vector<int>> dungeon;
int visited[10] = {0,};

void search(int energy, int cnt) {
    if (energy <= 0 || cnt == dungeon.size()) {
        return;
    }
    for (int i = 0; i < dungeon.size(); i++) {
        if (visited[i] != 0)
            continue;
        int min = dungeon[i][0];
        int use = dungeon[i][1];
        if (min > energy) {
            //cout << "skip" << i << endl;
            continue; 
        }
            
        visited[i] = 1;
        energy -= use;
        cnt += 1;
        if (cnt > answer) {
            answer = cnt;
            //cout << "answer: " << answer << endl;
            
        }
        //cout << "   visit " << i << endl;
        search(energy, cnt);
        //cout << "pop\n";
        visited[i] = 0;
        energy += use;
        cnt -= 1;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    now = k;
    dungeon = dungeons;
    
    search(k, 0);
    
    return answer;
}