#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int c;

bool cmp(vector<int> a, vector<int> b) {
    if (a[c - 1] == b[c - 1])
        return a[0] > b[0];
    return a[c - 1] < b[c - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    c = col;
    
    /* 2. col번째 칼럼 값 기준으로 오름차순 정렬한다. 
            그 값이 동일하면 첫 번째 칼럼의 값을 기준으로 내림차순 정렬한다. */
    sort(data.begin(), data.end(), cmp);
    
    /* 3. row_begin ~ row_end인 S_i를 구한다. */
    vector<int> s_i;
    for (int i = row_begin - 1; i <= row_end - 1; i++) {
        int s = 0;
        for (auto it : data[i])
            s += it % (i + 1);
        s_i.push_back(s);
    }
    
    /* 4. 모든 S_i를 bitwise XOR해 해시 값을 구한다. */
    int answer = s_i[0];
    for (int i = 1; i < s_i.size(); i++)
        answer = answer ^ s_i[i];
    
    return answer;
}