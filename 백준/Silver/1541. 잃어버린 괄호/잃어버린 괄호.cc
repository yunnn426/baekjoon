#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int parseNum(string num) {
    int n = 0;
    for (int i = 0; i < num.length(); i++) {
        n += (num[i] - '0') * pow(10, num.length() - i - 1);
    }
    return n;
}

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    vector<int> num_arr;
    vector<char> op_arr;
    string num = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '+' && s[i] != '-') { // 숫자 나오면
            num += s[i];
        }
        else { // 연산자 나오면 지금까지 나온 숫자 배열에 저장
            op_arr.push_back(s[i]);
            int n = parseNum(num);
            num_arr.push_back(n);
            num = "";
        }
        
        if (i == s.length() - 1) { // 식이 끝나면 숫자 처리
            int n = parseNum(num);
            num_arr.push_back(n);
            num = "";
        }
    }

    for (int i = 1; i < op_arr.size(); i++) { // - -> + + + ... : 괄호
        if (op_arr[i - 1] == '-') {
            int tmp = num_arr[i];
            int idx = i;
            while (op_arr[idx] == '+') {
                tmp += num_arr[idx + 1];
                num_arr[idx + 1] = 0;
                idx += 1;
            }
            num_arr[i] = tmp;
        }
    }
   
//    for (int i = 0; i < num_arr.size(); i++) {
//        cout << num_arr[i] << " ";
//    }
//    cout << endl;
//    
//    for (int i = 0; i < op_arr.size(); i++) {
//        cout << op_arr[i] << " ";
//    }
//    cout << endl;
    
    int answer = num_arr[0];
    for (int i = 0; i < op_arr.size(); i++) {
        int num1 = num_arr[i + 1];
        char op = op_arr[i];
        
        if (op == '-') {
            answer -= num1;
        }
        else {
            answer += num1;
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
