//
//  main.cpp
//  hello
//
//  Created by 황연경 on 12/31/23.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        sum += i;
        string s = to_string(i);
        for (int j = 0; j < s.length(); j++) {
            sum += s[j] - '0';
        }
        if (sum == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "0" << endl;
    return 0;
}

