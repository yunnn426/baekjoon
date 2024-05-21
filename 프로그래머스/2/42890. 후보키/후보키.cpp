#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> table;
int answer = 0, c, r;
vector<vector<int>> candidate;  // 가능한 후보키 집합 (최소성 만족 x)

map<vector<string>, int> make_map(vector<int> res) {
    map<vector<string>, int> m;
    
    // 해당하는 속성에 대해 맵을 만든다.
    for (int i = 0; i < r; i++) {
        vector<string> m1;   // map.first
        for (int k = 0; k < res.size(); k++) { 
            int att = res[k];
            m1.push_back(table[i][att]);
        }
        
        m[m1] += 1;
    } 
    
    return m;
}

void make_combination(vector<int> comb) {
    do {
        // 조합 배열
        // 가능한 속성들의 조합
        vector<int> res;        
        for (int j = 0; j < comb.size(); j++) {
            if (comb[j] == 1) {
                res.push_back(j);
            }
        }
        
        map<vector<string>, int> m = make_map(res);
        bool cand = true;
        for (auto it : m) {
            if (it.second != 1)
                cand = false;
        }
        
        // 매핑 시 카운트가 1이면 가능한 키 후보이다.
        // 속성 이름을 저장하지 않고 인덱스를 저장한다.
        if (cand) {
            candidate.push_back(res);
        }
        
    } while (next_permutation(comb.begin(), comb.end()));
}

void check_minimality() {
    for (auto it : candidate) {
        // 한 개짜리는 최소성을 만족한다.
        if (it.size() == 1) {
            answer += 1;
            continue;
        }
        
        // 하나씩 지워보면서 최소성을 만족하는지 체크한다.
        bool mini = false;
        for (int i = 0; i < it.size(); i++) {
            vector<int> tmp = it;
            tmp.erase(tmp.begin() + i);
            
            for (auto item : candidate) {
                if (item == tmp)
                    mini = true;
            }
        }
        if (!mini)
            answer += 1;
    }
}

int solution(vector<vector<string>> relation) {
    c = relation[0].size();     // 속성
    r = relation.size();        // 튜플
    table = relation;
    
    for (int i = 0; i <= c; i++) {
        // 조합을 만들기 위한 임시 배열
        vector<int> comb(c - i, 0);
        for (int a = 0; a < i; a++)
            comb.push_back(1);
        
        make_combination(comb);
    }
    
    check_minimality();
    
    return answer;
}