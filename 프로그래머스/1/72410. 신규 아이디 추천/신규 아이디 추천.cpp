#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1. 소문자로
    string phase1;
    for (int i = 0; i < new_id.length(); i++) {
        phase1 += tolower(new_id[i]);
    }
    //cout << phase1 << endl;
    
    // 2. ...를 제외한 모든 문자 제거
    string phase2;
    for (int i = 0; i < phase1.length(); i++) {
        int asc = phase1[i];
        if ((!((97 <= asc) && (asc <= 122))) && (!((48 <= asc) && (asc <= 57))) 
            && asc != 45 && asc != 95 && asc != 46) {
            continue;
        }
        else {
            phase2 += phase1[i];
        }
    }
    //cout << phase2 << endl;
    
    // 3. 마침표 2번 이상 하나로 치환
    string phase3;
    int cnt = 0;
    for (int i = 0; i < phase2.length(); i++) {
        if (phase2[i] == '.') {
            cnt += 1;
        }
        else {
            cnt = 0;
        }
        if (cnt > 1 && phase2[i] == '.') {
            continue;
        }
        else {
            phase3 += phase2[i];
        }
    }
    //cout << phase3 << endl;
    
    // 4. 처음, 끝에 위치한 마침표 제거
    string phase4;
    if (phase3[0] == '.' && phase3[phase3.length() - 1] == '.') { // 처음, 끝 모두 .
        phase4 += phase3.substr(1, phase3.length() - 1);
    }
    else if (phase3[0] == '.') { // 처음 .
        phase4 += phase3.substr(1, phase3.length());
    }
    else if (phase3[phase3.length() - 1] == '.') { // 끝 .
        phase4 += phase3.substr(0, phase3.length() - 1);
    }
    else {
        phase4 = phase3;
    }
    //cout << phase4 << endl;
    
    // 5. 빈 문자열 = "a"
    string phase5 = phase4;
    if (phase4.length() == 0) {
        phase5 = "a";
    }
    //cout << phase5 << endl;
    
    // 6. 16자 이상이면 첫 15개만
    string phase6 = phase5;
    if (phase6.length() >= 16) {
        phase6 = phase5.substr(0, 15);
    }
    if (phase6[phase6.length() - 1] == '.') {
        phase6 = phase6.substr(0, phase6.length() - 1);
    }
    //cout << phase6 << endl;
    
    // 7. 길이가 2자 이하
    string phase7 = phase6;
    if (phase7.length() <= 2) {
        while (phase7.length() < 3) {
            phase7 += phase6[phase6.length() - 1]; 
        }
    }
    //cout << phase7 << endl;
    
    answer = phase7;
    
    return answer;
}