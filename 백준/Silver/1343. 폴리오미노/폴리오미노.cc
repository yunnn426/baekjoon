//
//  main.cpp
//  hello
//
//  Created by 황연경 on 12/31/23.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    string s, answer, news;
    cin >> s;
    
    while (s.find("XXXX") != string::npos) {
        s.replace(s.find("XXXX"), 4, "AAAA");
    }
    while (s.find("XX") != string::npos) {
        s.replace(s.find("XX"), 2, "BB");
    }
    
    if (s.find("X") != string::npos) { //문자열에 아직도 X가 존재하면
        cout << "-1" << endl;
    }
    else {
        cout << s << endl;
    }
    return 0;
}

