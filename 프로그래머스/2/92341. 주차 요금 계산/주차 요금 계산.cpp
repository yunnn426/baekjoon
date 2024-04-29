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

    while (getline(iss, buffer, ' ')) {
        result.push_back(buffer);
        //cout << buffer << endl;
    }
    
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<vector<string>> car_record;
    map<string, int> res;
    
    // fees
    int b_time = fees[0];
    int b_fee = fees[1]; 
    int t_time = fees[2];
    int t_fee = fees[3];
    int in_hour, in_min, out_hour, out_min, in_time, out_time, time;
    
    for (int i = 0; i < records.size(); i++) {
        vector<string> split_r1 = split_record(records[i]);
        string c_num1 = split_r1[1];

        if (split_r1[2] == "OUT")
            continue;
        
        bool found = false; // 입차 후 출차하였는지 체크
        vector<string> split_r2;
        for (int j = i + 1; j < records.size(); j++) {
            split_r2 = split_record(records[j]);
            string c_num2 = split_r2[1];
            if (c_num1 == c_num2) { // 입차-출차 짝이 맞으면
                found = true;
                break;
            }
        }
        
        // cal time
        if (found) {
            in_hour = stoi(split_r1[0].substr(0, 2));
            in_min = stoi(split_r1[0].substr(3, 2));
            out_hour = stoi(split_r2[0].substr(0, 2));
            out_min = stoi(split_r2[0].substr(3, 2));
        }
        else {
            in_hour = stoi(split_r1[0].substr(0, 2));
            in_min = stoi(split_r1[0].substr(3, 2));
            out_hour = 23;
            out_min = 59;
        }
        in_time = in_hour * 60 + in_min;
        out_time = out_hour * 60 + out_min;
        time = out_time - in_time;

        bool before = false;
        for (auto item : res) {
            if (item.first == c_num1) {
                item.second += time;
                res.erase(c_num1);
                res.insert({c_num1, item.second});
                before = true;
                break;
            }
        }
        
        if (!before)
            res.insert({c_num1, time});
        
    }
    
    for (auto item : res) {
        int fee;
        int time = item.second;

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