#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> word;
string tgt;
int answer = 100000;
int visited[55] = {0,};

void search(string s, int cnt) {
    if (s == tgt) {
        answer = min(answer, cnt);
        //cout << cnt << " " << answer << endl;
        return;
    }
    
    for (int i = 0; i < word.size(); i++) {
        if (visited[i] != 0)
            continue;
        
        int diff = 0;
        for (int j = 0; j < word[i].length(); j++) {
            if (s[j] != word[i][j])
                diff += 1;
        }
        // 2글자 이상 다르면 패스
        if (diff > 1)
            continue;
        
        visited[i] = 1;
        search(word[i], cnt + 1);
        visited[i] = 0;
    }
}

int solution(string begin, string target, vector<string> words) { 
    word = words;
    tgt = target;
    
    // 변환할 수 없는 경우
    bool psbl = false;
    for (int i = 0; i < words.size(); i++) {
        if (target == words[i])
            psbl = true;
    }
    if (!psbl) 
        return 0;
    
    // 변환
    search(begin, 0);
    
    return answer;
}