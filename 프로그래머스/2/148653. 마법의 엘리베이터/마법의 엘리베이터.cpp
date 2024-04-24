#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solve(int storey) {
    if (storey == 0)
        return 0;
    if (storey == 1)
        return 1;
    
    return min(storey % 10 + solve(storey / 10), 10 - storey % 10 + solve(storey / 10 + 1));
}

int solution(int storey) {
    int answer = solve(storey);
    
    return answer;
}