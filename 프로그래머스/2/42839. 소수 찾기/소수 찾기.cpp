#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>

#define MAX 9999999

using namespace std;

int len, answer = 0;
string number;
set<int> possible;
int visited[10] = {0,};
int primeArr[MAX + 10] = {0,}; // 0이면 소수

void search(int cnt, int num) {
    if (cnt == len) {
        
        return;
    }
    for (int i = 0; i < len; i++) {
        string s = to_string(num);
        if (visited[i] != 0)
            continue;
        
        s += number[i];
        visited[i] = 1;
        int ii = stoi(s);
        if (ii > 1)
            possible.insert(ii);
        
        search(cnt + 1, ii);
        
        visited[i] = 0;
        cnt -= 1;
    }
}

int solution(string numbers) {
    number = numbers;
    len = numbers.length();
    
    search(0, 0);
    
    auto maxx = possible.rbegin(); // 만들 수 있는 가장 큰 수
    int max = *maxx;
    // 2부터 max까지 소수 구하기
    for (int i = 2; i <= sqrt(max); i++) {
        for (int j = 2; i * j <= max; j++) {
            primeArr[i * j] = 1;
        }
    }

    for (auto iter = possible.begin(); iter != possible.end(); iter++) {
        if (primeArr[*iter] == 0) {
            answer += 1;
        }
    }
    
    return answer;
}