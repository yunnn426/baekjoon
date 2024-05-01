#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> m;
    sort(phone_book.begin(), phone_book.end());
    
    int cnt = 0;
    for (auto p : phone_book) {
        string sub = p.substr(0, cnt);
        if (m[sub] == 0) { // 접두사가 아니면 번호 맵에 추가
            m[p] = 1;
        }
        else {
            return false;
        }
        cnt = p.length();
    }
        
    return answer;
}