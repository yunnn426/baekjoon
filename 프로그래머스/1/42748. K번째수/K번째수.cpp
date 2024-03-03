#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int t = 0; t < commands.size(); t++) {
        vector<int> arr = array;
        int i = commands[t][0];
        int j = commands[t][1];
        int k = commands[t][2];
        sort(arr.begin() + i - 1, arr.begin() + j);
        answer.push_back(arr[i + k - 2]);
    }
    return answer;
}