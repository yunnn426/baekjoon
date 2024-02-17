#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1; i < 2500; i++) { // 세로
        for (int j = 1; j < 2500; j++) { // 가로
            if (i > j)
                continue;
            int b = j * 2 + (i - 2) * 2;
            int y = (i - 2) * (j - 2);
            if (b == brown && y == yellow) {
                answer.push_back(j);
                answer.push_back(i);
            }
        }
    }
    
    return answer;
}