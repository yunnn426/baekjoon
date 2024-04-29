#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;


vector<string> split_record(string record) {
    istringstream iss(record);
    string buffer;
    vector<string> result;

    while (getline(iss, buffer, ' '))
        result.push_back(buffer);
    
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<int>> res; // 차 - 요금 - 카운트
    
    // fees
    int b_time = fees[0];
    int b_fee = fees[1]; 
    int t_time = fees[2];
    int t_fee = fees[3];
    int in_hour, in_min, out_hour, out_min, in_time, out_time, time;
    
    for (int i = 0; i < records.size(); i++) {
        vector<string> split_r1 = split_record(records[i]);
        string c_time = split_r1[0];
        string c_num1 = split_r1[1];
        string c_log = split_r1[2];
        
        int hour = stoi(c_time.substr(0, 2));
        int min = stoi(c_time.substr(3, 2));
        int t = hour * 60 + min;
        
        if (c_log == "IN")
            t *= -1;
        
        bool found = false;
        auto item = res.find(c_num1);
        if (item != res.end()) {
            int new_time = item->second[0] + t;
            int count = item->second[1] + 1;
            vector<int> tmp;
            tmp.push_back(new_time);
            tmp.push_back(count);
            res.erase(c_num1);
            res.insert({c_num1, tmp});
        }
        else {
            vector<int> tmp;
            tmp.push_back(t);
            tmp.push_back(1);
            res.insert({c_num1, tmp});
        }
    }
    
    for (auto item : res) {
        int fee;
        int time = item.second[0];
        int cnt = item.second[1];
        
        if (cnt % 2 != 0) // 입-출 짝 안맞으면
            time += 23 * 60 + 59; // 23:59에 출차

        if (time < b_time) {
            fee = b_fee;
        }
        else {
            if ((time - b_time) % t_time == 0) {
                fee = b_fee + (time - b_time) / t_time * t_fee;
            }
            else {
                fee = b_fee + ((time - b_time) / t_time + 1) * t_fee;
            }
        }
        answer.push_back(fee);
    }
    
    return answer;
}