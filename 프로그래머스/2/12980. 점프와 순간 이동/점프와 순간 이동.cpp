#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n)
{
    int ans = 0;
    
    /* 5000 -> 2500 -> 1250 -> 625(624, ans++) -> 312 ... -> 1(ans++) */
    while (n >= 1) {
        if (n % 2 != 0) {
            ans += 1;
            n -= 1;
        }
        
        n /= 2;
    }
    
    return ans;
}