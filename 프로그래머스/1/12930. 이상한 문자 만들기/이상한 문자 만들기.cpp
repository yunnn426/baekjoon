#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int tmp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            tmp = 0;
            continue;
        }
        if (tmp % 2 == 0) {
            s[i] = toupper(s[i]);
        }
        else {
            s[i] = tolower(s[i]);
        }
        tmp += 1;
    }
    answer = s;
    return answer;
}