#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_idx(char c) {
    switch (c) {
        case 'R':
            return 0;
        case 'T':
            return 1;
        case 'C':
            return 2;
        case 'F':
            return 3;
        case 'J':
            return 4;
        case 'M':
            return 5;
        case 'A':
            return 6;
        case 'N':
            return 7;
    }
}

string check_letter(int i) {
    switch (i) {
        case 0:
            return "R";
        case 1:
            return "T";
        case 2:
            return "C";
        case 3:
            return "F";
        case 4:
            return "J";
        case 5:
            return "M";
        case 6:
            return "A";
        case 7:
            return "N";
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int all_scores[8] = {0,};
    
    for (int i = 0; i < survey.size(); i++) {
        int score = 0, idx = 0;
        int choice = choices[i];
        
        if (choice < 4) { // survey의 앞글자 점수
            idx = check_idx(survey[i][0]);
            score = 4 - choice;
        }
        else if (choice > 4) { // survey의 뒷글자 점수
            idx = check_idx(survey[i][1]);
            score = choice - 4;
        }
        
        all_scores[idx] += score;
    }
    
    // 결과 계산
    for (int i = 0; i <= 6; i += 2) {
        string ans = "";
        if (all_scores[i] >= all_scores[i + 1]) {
            ans = check_letter(i);
        }
        else {
            ans = check_letter(i + 1);
        }
        answer.append(ans);
    }
    
    return answer;
}