#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int b_min = fees[0]; // 기본 시간
    int b_fee = fees[1]; // 기본 요금
    int p_min = fees[2]; // 단위 시간
    int p_fee = fees[3]; // 단위 요금
    
    // 차량번호 배열
    set<string> car_nums;
    for (int i = 0; i < records.size(); i++) {
        string car = records[i].substr(6, 4);
        car_nums.insert(car);
    }
    
    for (auto iter = car_nums.begin(); iter != car_nums.end(); iter++) {
        int intime = -1;
        int outtime = -1;
        int timesum = 0;
        
        for (int i = 0; i < records.size(); i++) {
            string time = records[i].substr(0, 5);
            string car = records[i].substr(6, 4);
            string inout = records[i].substr(11, 2);
            
            if (car == *iter) {
                if (inout == "IN") {
                    intime = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
                    cout << "IN: " << intime << endl;
                }
                else {
                    outtime = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
                    cout << "OUT: " << outtime << endl;
                    timesum += outtime - intime;
                    intime = -1;
                    outtime = -1;
                }
            }
            
            
        }
        
        if (intime != -1) { // records를 다 돌았는데도 출차 기록을 찾지 못함 (23:59에 출차)
            timesum += 1439 - intime;
        }
        
        int fee = 0;
        if (timesum <= b_min) {
            fee = b_fee;
        }
        else {
            double over_min = (timesum - b_min) / (double)p_min;
            int over = over_min;
            if (fmod(over_min, 1) != 0) { // 단위시간으로 나누어 떨어지지 않으면
                over += 1;
            }
            fee = b_fee + over * p_fee;
        }
        
        answer.push_back(fee);
    }
    
    
    return answer;
}