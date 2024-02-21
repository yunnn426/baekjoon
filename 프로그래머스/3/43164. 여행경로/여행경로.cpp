#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
vector<string> answer;
vector<string> result;
vector<string> airport;
int used[10010][10010] = {0,};
bool found = false; // 가능한 첫 조합 찾으면 바로 리턴하도록

int find_idx(string s) {
    int idx = 0;
    for (int j = 0; j < airport.size(); j++) {
        if (airport[j] == s) {
            idx = j;
            break;
        } 
    }
    return idx;
}

void search(int from) {
    if (found)
        return;
    if (result.size() == n) {
        found = true;
        answer = result;
        return;
    }
    for (int j = 0; j < airport.size(); j++) {
        if (used[from][j] == 0)
            continue;
        used[from][j] -= 1;
        result.push_back(airport[j]);
        search(j);
        used[from][j] += 1;
        result.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // 알파벳순 정렬
    sort(tickets.begin(), tickets.end());
    
    // 공항 배열 생성 (알파벳순 정렬)
    for (int i = 0; i < tickets.size(); i++) {
        string from = tickets[i][0];
        string to = tickets[i][1];
        
        bool found1 = false; bool found2 = false; // from, to에 해당하는 공항이 이미 저장되어있는지 확인
        for (int j = 0; j < airport.size(); j++) {
            if (airport[j] == from)
                found1 = true;
            if (airport[j] == to)
                found2 = true;
        }
        
        if (!found1)
            airport.push_back(from);
        if (!found2)
            airport.push_back(to);
    }
    sort(airport.begin(), airport.end());
    
    // 표 개수 계산
    for (int i = 0; i < tickets.size(); i++) {
        string from = tickets[i][0];
        string to = tickets[i][1];
        
        int from_idx = find_idx(from);
        int to_idx = find_idx(to);
        
        used[from_idx][to_idx] += 1;
    }
    
    n = tickets.size() + 1;
    
    result.push_back("ICN");
    search(find_idx("ICN")); // ICN으로 시작
    
    return answer;
}