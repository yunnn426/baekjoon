#include <iostream>
#include <map>

using namespace std;

int main() {
    int p, m;
    cin >> p >> m;
    
    int room_level[p] = {0,}; // 방 입장 기준 레벨
    map<string, int> room[p];

    int count = 0; // 활성화 된 방 수
    for (int i = 0; i < p; i++) {
        int level;
        string name;
        cin >> level >> name;

        for (int j = 0; j <= count; j++) {
            if (room_level[j] == 0) {
                room_level[j] = level;
                room[j].insert({name,level});
                count++;
                break;
            }
            if (room[j].size() < m && room_level[j] - 10 <= level && level <= room_level[j] + 10) {
                room[j].insert({name,level});
                break;
            }
        }
    }

    
    for (int i = 0; i < p; i++) {
        if (room_level[i] == 0) {
            break;
        }
        
        if (room[i].size() == m) {
            cout << "Started!" << endl;
        }
        else {
            cout << "Waiting!" << endl;
        }

        for (auto iter = room[i].begin(); iter != room[i].end(); iter++) {
            cout << iter->second << " " << iter->first << endl;
        }
    }

	return 0;
}