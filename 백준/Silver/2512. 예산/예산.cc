#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, budget, answer = -1, sum = 0;
    cin >> n;
    int request[10010] = {0,};
    for (int i = 0; i < n; i++) {
        cin >> request[i];
        sum += request[i];
    }
    cin >> budget;
    sort(request, request + n);
    
    if (sum <= budget) { // 모든 요청 배정 가능
        answer = request[n - 1];
    }
    else { // 모든 요청 배정 불가능
        int start = 0; // 가장 작은 예산도 배정 불가능할 경우 고려
        int end = request[n - 1];
        
        int mid = (start + end) / 2;
        while (start < mid) {
            int tmp_sum = 0;
            for (int i = 0; i < n; i++) {
                if (request[i] <= mid) {
                    tmp_sum += request[i];
                }
                else {
                    tmp_sum += mid;
                }
            }
            if (tmp_sum < budget) { // 예산보다 작으면 뒤쪽 절반으로 이동
                start = mid;
                mid = (start + end) / 2;
            }
            else if (tmp_sum > budget){ // 예산보다 크면 앞쪽 절반으로 이동
                end = mid;
                mid = (start + end) / 2;
            }
            else {
                break;
            }
            //cout << start << " " << mid << " " << end << endl;
        }
        answer = mid;
    }
    
    cout << answer << "\n";
    
    return 0;
}
