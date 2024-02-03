#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    // 보조 배열 {0, 0, ..., 1, 1, 1}
    vector<int> subArr;
    for (int i = 0; i < nums.size(); i++) {
        subArr.push_back(0);
    }
    for (int i = nums.size() - 3; i < nums.size(); i++) {
        subArr[i] = 1;
    }
    
    vector<int> sumArr; // 3개 수 합들의 배열
    // 5C3을 수행하며 가능한 모든 합 구하기
    do {
        int sum = 0;
        for (int i = 0; i < subArr.size(); i++) {
            if (subArr[i] == 1) {
                sum += nums[i];
            }
        }
        sumArr.push_back(sum);
        
    } while (next_permutation(subArr.begin(), subArr.end()));
    
    sort(sumArr.begin(), sumArr.end());
    
    int isPrime[50000];
    fill(isPrime, isPrime + 5000, 1);
    
    int max = sumArr[sumArr.size() - 1];
    // 가장 큰 합까지의 소수 구하기
    for (int i = 2; i <= sqrt(max); i++) {
        if (isPrime[i] == 0)
            continue;
        for (int j = 2; i * j <= max; j++) {
            isPrime[i * j] = 0;
        }
    }
    
    
    for (int i = 0; i < sumArr.size(); i++) {
        if (isPrime[sumArr[i]] == 1) {
            answer += 1;
        }
    }
    
    return answer;
}