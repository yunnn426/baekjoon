#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n_emo;
vector<vector<int>> user;
vector<int> emoticon;
vector<vector<int>> sale_sum; // 할인율 조합 별 result
int arr[10]; // 할인율 조합

bool desc(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }
    else {
        return a[0] > b[0];
    }
}

void search(int cnt) {
    if (cnt == n_emo) {
        vector<int> user_spend(user.size(), 0);
        for (int i = 0; i < n_emo; i++) {
            int rate = arr[i];
            int price = emoticon[i] - (emoticon[i] * rate / 100);
            for (int j = 0; j < user.size(); j++) {
                if (rate < user[j][0]) {
                    continue;
                }
                user_spend[j] += price;
            }
        }
        
        int eplus = 0;
        int income = 0;
        for (int i = 0; i < user_spend.size(); i++) {
            if (user_spend[i] >= user[i][1]) { // 가격 이상이면 이모티콘 플러스 가입
                eplus += 1;
            }
            else {
                income += user_spend[i];
            }
        }
        vector<int> tmp;
        tmp.push_back(eplus);
        tmp.push_back(income);
        sale_sum.push_back(tmp);
        
        return;
    }
    
    //cout << "cnt: " << cnt << endl;
    for (int i = 10; i <= 40; i += 10) {
        arr[cnt] = i;
        search(cnt + 1);
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    user = users;
    emoticon = emoticons;
    n_emo = emoticons.size();
    
    for (int i = 10; i <= 40; i += 10) {
        arr[0] = i;
        search(1);
    }
    
    // 행사 목적 달성한 순으로 정렬
    sort(sale_sum.begin(), sale_sum.end(), desc);

    answer = sale_sum[0];
    
    return answer;
}