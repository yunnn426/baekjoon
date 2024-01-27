#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<pair<string, vector<string>>> reported_id; // 유저마다 신고한 id list
    vector<pair<string, int>> n_reported; // 유저마다 신고당한 횟수
    vector<string> suspended; // 정지당한 유저 Id
    
    for (int i = 0; i < id_list.size(); i++) { // 두 배열 Init
        vector<string> tmp;
        reported_id.push_back(make_pair(id_list[i], tmp));
        n_reported.push_back(make_pair(id_list[i], 0));
    }
    
    for (int i = 0; i < report.size(); i++) {
        string reporter = "";
        string reported = "";
        int idx = 0;
        while (report[i][idx] != ' ') {
            reporter.push_back(report[i][idx]);
            idx += 1;
        }
        reported = report[i].substr(idx + 1);
        
        
        for (int j = 0; j < reported_id.size(); j++) {
            if (reported_id[j].first == reporter) { // reported_id 배열 업데이트
                auto it = find(reported_id[j].second.begin(), reported_id[j].second.end(), reported);
                if (it == reported_id[j].second.end()) { // 처음 신고하면 추가
                    reported_id[j].second.push_back(reported);
                    for (int k = 0; k < n_reported.size(); k++) { // 신고당한 id의 신고횟수 +1
                        if (n_reported[k].first == reported) {
                            n_reported[k].second += 1;
                        }
                    }
                }
            }
        }
        
    }
    
    // reported_id 출력
    // for (int i = 0; i < reported_id.size(); i++) {
    //     cout << reported_id[i].first << ": ";
    //     for (int j = 0; j < reported_id[i].second.size(); j++) {
    //         cout << reported_id[i].second[j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // n_reported 출력
    for (int i = 0; i < n_reported.size(); i++) {
        //cout << n_reported[i].first << ": " << n_reported[i].second << endl;
        if (n_reported[i].second >= k) {
            suspended.push_back(n_reported[i].first);
        }
    }
    
    // 정지당한 유저
    // for (int i = 0; i < suspended.size(); i++) {
    //     cout << suspended[i] << endl;
    // }
    
    for (int i = 0; i < reported_id.size(); i++) {
        int ans = 0;
        for (int j = 0; j < suspended.size(); j++) {
            string id_suspend = suspended[j];
            auto it = find(reported_id[i].second.begin(), reported_id[i].second.end(), id_suspend);
            if (it != reported_id[i].second.end()) { // 정지당한 유저를 신고한 경우
                ans += 1;
            }
        }
        answer.push_back(ans);
    }
    
    return answer;
}