#include <iostream>

using namespace std;


int main() {
    int N;
    cin >> N;

    int head = -1; //머리가 위치한 인덱스
    int head_x = -1;

    bool found_arm = false;

    int l_arm = 0, r_arm = 0;
    int waist = 0;
    int l_leg = 0, r_leg = 0;


    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        
        //머리 찾기
        if (head == -1) {
            for (int j = 0; j < N; j++) {
                if (line[j] == '*') {
                    head = j;
                    head_x = i;
                }
            }
            continue;
        }

        
        //팔 찾기
        if (found_arm == false) {
            for (int j = 0; j < head; j++) {
                if (line[j] == '*') {
                    l_arm++;
                }
            }

            for (int j = head+1; j < N; j++) {
                if (line[j] == '*') {
                    r_arm++;
                }
            }
            found_arm = true;
            continue;
        }

        //허리+다리 찾기
        if (line[head] == '*') {
            waist++;
        }

        else {
            if (line[head-1] == '*') {
                l_leg++;
            }

            if (line[head+1] == '*') {
                r_leg++;
            }
        }
    }

    cout << head_x + 2 << " " << head + 1 << endl;
    cout << l_arm << " " << r_arm << " " << waist << " " << l_leg << " " << r_leg << endl;
    
    return 0;
}