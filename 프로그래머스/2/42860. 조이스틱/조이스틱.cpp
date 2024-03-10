#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int up(char start, char end) {
    int step = 0;
    if (start == end)
        return 0;
    for (int i = 1; i < 26; i++) {
        start += 1;
        if (start > 90)
            start = 65;
        if (start == end) {
            step = i;
            break;
        }
    }
    return step;
}

int down(char start, char end) {
    int step = 0;
    if (start == end)
        return 0;
    for (int i = 1; i < 26; i++) {
        start -= 1;
        if (start < 65)
            start = 90;
        if (start == end) {
            step = i;
            break;
        }
    }
    return step;
}

int solution(string name) {
    string s = "";
    for (int i = 0; i < name.length(); i++) {
        s += "A";
    }
    
    if (name == s) // name == "AAA"
        return 0;
    
    // 알파벳 변경
    int len = name.length();
    int mins = len - 1;
    int answer = 0;
    for (int i = 0; i < name.length(); i++) {
        if (s[i] != name[i])
            answer += min(up(s[i], name[i]), down(s[i], name[i]));

        int idx = i + 1;
        while (name[idx] == 'A')
            idx += 1;
        mins = min(mins, i + len - idx + min(i, len - idx));
    }
    answer += mins;
    
    return answer;
}