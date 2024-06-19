#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* 배열 길이 오름차순 정렬 */
bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<vector<int>> seq;
    
    /* s -> 정수 배열 */
    vector<int> v;
    s = s.substr(1, s.length() - 2);
    string num = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            v.clear();
        }
        else if (s[i] == ',' && s[i - 1] != '}') {  // {} 안에 있는 ,
            v.push_back(stoi(num));
            num = "";
        }
        else if (s[i] == '}') {
            v.push_back(stoi(num));
            num = "";
            seq.push_back(v);
        }
        else if (s[i] == ',') { // {} 밖의 ,
            continue;
        }
        else {
            num += s[i];
        }
    }
    
    // 정답 배열 개수는 seq의 개수
    int n = seq.size();
    // 정렬
    sort(seq.begin(), seq.end(), cmp);
    
    vector<int> answer;    
    /* 길이가 짧은 배열에 있는 수부터 튜플에 넣어야 한다. */
    for (auto it : seq) {
        for (int i = 0; i < it.size(); i++) {
            if (find(answer.begin(), answer.end(), it[i]) != answer.end())    // 이미 튜플에 있는 원소
                continue;
            answer.push_back(it[i]);
        }
    }
    
    return answer;
}