#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        bool found = false;
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[j] < prices[i]) {
                answer.push_back(j - i);
                found = true;
                break;
            }
        }
        if (!found)
            answer.push_back(prices.size() - 1 - i);
    }
    return answer;
}