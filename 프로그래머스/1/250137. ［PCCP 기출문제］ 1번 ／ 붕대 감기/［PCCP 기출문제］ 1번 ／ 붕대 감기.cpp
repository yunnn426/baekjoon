#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    
    int totaltime = attacks.back()[0];
    int now_health = health;
    int heal_count = 0;
    for (int time = 0; time <= totaltime; time++) {
        bool isattacked = false;
        int damage;
        // 공격 당했는가
        for (int i = 0; i < attacks.size(); i++) {
            if (time == attacks[i][0]) {
                isattacked = true;
                damage = attacks[i][1];
            }
        }
        
        if (!isattacked) {
            heal_count += 1;
            if (now_health < health) {
                now_health = (now_health + x) > health ? health : now_health + x;
            }
            // 시전시간 채우면
            if (heal_count == t) {
                now_health = (now_health + y) > health ? health : now_health + y;
                heal_count = 0;
            }
        }
        else {
            heal_count = 0;
            now_health -= damage;
        }
        
        //cout << "time: " << time << ", now_health: " << now_health << endl;
        
        if (now_health <= 0)
            break;
        
    }
    
    if (now_health <= 0)
        answer = -1;
    else
        answer = now_health;
    
    return answer;
}