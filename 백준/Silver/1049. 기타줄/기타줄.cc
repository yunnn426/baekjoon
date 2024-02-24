#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    int pkg = 1000, piece = 1000; // 가장 저렴한 패키지 가격, 낱개 가격
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a < pkg)
            pkg = a;
        if (b < piece)
            piece = b;
    }
    
    int a = n / 6;
    int b = n % 6;
    int answer = min({a * pkg + b * piece, pkg * (a + 1), n * piece}); // 패키지 + 낱개 vs 패키지로만 vs 낱개로만
    cout << answer << endl;
    
    return 0;
}

