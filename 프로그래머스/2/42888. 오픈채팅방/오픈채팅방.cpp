#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> users; // id - nickname 저장
    vector<string> order; // 들어온 순서 저장
    
    for (int i = 0; i < record.size(); i++) {
        // record input
        string s = record[i];
        string id = "", nickname = "";
        for (int j = 1; j < s.size(); j++) {
            if (s[j - 1] == ' ' && id == "") { // id input 첫글자
                id += s[j];
            }
            else if (s[j - 1] == ' ' && nickname == "") { // nickname input 첫글자
                nickname += s[j];
            }
            else if (id != "" && nickname == "" && s[j] != ' ') { // id input 나머지 글자
                id += s[j];
            }
            else if (nickname != "" && s[j] != ' ') { // nickname input 나머지 글자
                nickname += s[j];
            }
        }
        
        // 맵에 저장
        if (id != "" && nickname != "") {
            if (users.find(id) != users.end()) // 찾으면
                users.erase(id);
        }
        users.insert({id, nickname});
        order.push_back(id);
    }
    
    // result
    for (int i = 0; i < record.size(); i++) {
        string s = record[i], menu = "", id = "";
        
        for (int j = 0; j < s.size(); j++) {
            if (menu == "") {
                menu += s[j];
            }
            else if (id == "" && s[j] == ' ') {
                id += s[j];
            }
            else if (menu != "" && id == "" && s[j] != ' ') {
                menu += s[j];
            }
            else if (id != "" && s[j] != ' ') {
                id += s[j];
            }
            else if (id != "" && menu != "" && s[j] == ' ') {
                break;
            }
        }
        
        id = id.substr(1);
        string ss = "";
        auto item = users.find(id);
        if (item != users.end())
            ss += item->second;

        bool flag = true;
        switch (menu[0]) {
            case 'E':
                ss += "님이 들어왔습니다.";
                break;
            case 'L':
                ss += "님이 나갔습니다.";
                break;
            case 'C':
                flag = false;
            default:
                break;
        }
        if (!flag) // change는 출력x
            continue;

        answer.push_back(ss);
    }
    
    return answer;
}