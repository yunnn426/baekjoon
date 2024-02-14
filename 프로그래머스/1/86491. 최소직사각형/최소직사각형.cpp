#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int max_w = 0;
    int max_h = 0;
    for (int i = 0; i < sizes.size(); i++) {
        int a = sizes[i][0];
        int b = sizes[i][1];
        if (b > a) {
            sizes[i][0] = b;
            sizes[i][1] = a;
        }
        
        if (sizes[i][0] > max_w) {
            max_w = sizes[i][0];
        }
        if (sizes[i][1] > max_h) {
            max_h = sizes[i][1];
        }
    }
    
    answer = max_w * max_h;
    
    return answer;
}