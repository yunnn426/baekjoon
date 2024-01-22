#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int year = 1000 * (today[0] - '0') + 100 * (today[1] - '0') + 10 * (today[2] - '0') + (today[3] - '0');
    int month = 10 * (today[5] - '0') + (today[6] - '0');
    int day = 10 * (today[8] - '0') + (today[9] - '0');
    
    map<string, int> terms_map;
    for (int i = 0; i < terms.size(); i++) {
        string c = terms[i].substr(0, 1);
        string d = terms[i].substr(2);
        int days = stoi(d);
        
        terms_map.insert(pair<string, int>(c, days));
    }
    
    map<string, int>::iterator it;
    for (int i = 0; i < privacies.size(); i++) {
        string cdate = privacies[i].substr(0, 10);
        string level = privacies[i].substr(11);
        int cyear = stoi(cdate.substr(0, 4));
        int cmonth = stoi(cdate.substr(5, 7));
        int cday = stoi(cdate.substr(8, 10));
        
        it = terms_map.find(level);
        int valid = it->second;
        
        // 유효기간 계산
        int v_year = 0, v_month = 0;
        v_year = valid / 12;
        v_month = valid % 12;
        int new_month = cmonth + v_month;
        int new_year = cyear + v_year;
        int new_day = cday - 1;
        
        //cout << new_year << " " << new_month << " " << new_day << " " << endl;
        
        if (new_day == 0) {
            new_month -= 1;
            new_day = 28;
            if (new_month == 0) {
                new_year -= 1;
                new_month = 12;
            }
        }
        if (new_month > 12) {
            new_year += 1;
            new_month -= 12;
        }
        
        // 오늘날짜와 비교
        bool haspassed = false;
        if (new_year < year) { // 유효기간 지남
            haspassed = true;
        }
        else if (new_year == year) {
            if (new_month < month) {
                haspassed = true;
            } 
            else if (new_month == month) {
                if (new_day < day) {
                    haspassed = true;
                }
            }
        }
        
        //cout << new_year << " " << new_month << " " << new_day << " " << haspassed << endl;
        
        if (haspassed)
            answer.push_back(i + 1);
    }
    
    return answer;
}