#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(long long n) {
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    // k진수로 변환
    int tmp = 1, cnt = 0;
    string cv = "";
    while (n >= tmp) {
        int i = (n / tmp) % k;
        cv = to_string(i) + cv;
        tmp *= k;
        cnt += 1;
    }
    
    string s = "";
    for (int i = 0; i < cv.length(); i++) {
        if (cv[i] == '0') { // 0 만나면 소수인지 판단 
            if (s == "")
                continue;
            long long l = stol(s);
            if (isPrime(l) && l != 1)
                answer += 1;
            s = "";
        }
        else {
            s += cv[i];
        }
    }
    
    if (s != "") { // 남은 문자열 처리
        long long l = stol(s);
        if (isPrime(l) && l != 1)
            answer += 1;
    }
    
    return answer;
}