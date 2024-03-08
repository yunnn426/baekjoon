#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <cmath>

using namespace std;

string makeTree(string num) {
    int n = 1;
    while (num.length() > pow(2, n) - 1)
        n += 1;
    while (num.length() != pow(2, n) - 1) {
        num = "0" + num;
    }
    return num;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (int i = 0; i < numbers.size(); i++) {
        // 이진수로 변환
        long long n = numbers[i];
        string num = "";
        while (n > 0) {
            int m = n % 2;
            num = to_string(m) + num;
            n /= 2;
        }
        
        // 포화 이진트리 만들기
        if (num.length() <= 1) {
            if (num == "") {
                answer.push_back(0);
                continue;
            }
        }
        else
            num = makeTree(num);
        
        // 자식노드가 1일때 부모노드도 1인지 계산
        int root = (num.length() + 1) / 2; // 루트 노드의 번호
        bool can = true;

        for (int j = 0; j < num.length(); j++) {
            if (num[j] == '0') 
                continue;
            // 자식노드가 1인 경우
            int r = root, d = r / 2, cnt = log2(num.length() + 1) - 1;
            while (cnt > 0) {
                if (j + 1 == r)
                    break;
                if (num[r - 1] == '0') {
                    can = false;
                    break;
                }
                if ((j + 1) > r)
                    r += d;
                else 
                    r -= d;
                cnt -= 1;
                d /= 2;
            }
            if (!can)
                break;
        }

        // 표현 가능하면 1, 아니면 0
        if (can)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}