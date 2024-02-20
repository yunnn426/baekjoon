#include <string>
#include <vector>
#include <iostream>

using namespace std;

string w;
int answer = 0, cnt = 0;
char alp[5] = {'A', 'E', 'I', 'O', 'U'};

void search(string s) {
    //cout << s << "(" << s.length() << ")" << " : " << cnt << endl;
    if (s == w) {
        answer = cnt;
        return;
    }
    if (s.length() == 5) {
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        cnt += 1;
        search(s + alp[i]);  
    }
}

int solution(string word) {
    w = word;
    
    search("");
    
    return answer;
}