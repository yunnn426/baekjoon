#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;

void bfs(string start, string end, vector<string> word) {
    queue<pair<string, int>> q;
    q.push(make_pair(start, 0));
    int n = word.size();
    vector<int> visited(n, 0);
    
    while (!q.empty()) {
        string str = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (str == end) {
            answer = cnt;
            break;
        }
        
        for (int i = 0; i < word.size(); i++) {
            if (visited[i] != 0)
                continue;
            
            /* words 배열에서 한 글자 차이나는 단어 찾기 */
            string s = word[i];
            
            int diff = 0;
            for (int idx = 0; idx < s.length(); idx++) {
                if (s[idx] != str[idx])
                    diff += 1;
            }

            if (diff == 1) {
                q.push(make_pair(s, cnt + 1));
                visited[i] = 1;
            }
        }
        
    }
}

int solution(string bgn, string tgt, vector<string> words) {
    bool in = false;
    for (auto it : words) {
        if (it == tgt)
            in = true;
    }
    
    // words 안에 없기 때문에 변환할 수 없습니다.
    if (!in)
        return answer;
    
    bfs(bgn, tgt, words);
    
    return answer;
}