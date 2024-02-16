#include <string>
#include <vector>

using namespace std;

int n, tar, ans = 0;
vector<int> number;

void search(int cnt, int sum) {
    if (cnt == n) {
        if (sum == tar) {
            ans += 1;
        }
        return;
    }
    
    search(cnt + 1, sum + number[cnt]);
    search(cnt + 1, sum - number[cnt]);
}

int solution(vector<int> numbers, int target) {
    
    number = numbers;
    n = numbers.size();
    tar = target;
    
    search(0, 0);
    
    return ans;
}