#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;
	
    queue<int> q;

	for (int i = 0; i < N; i++) {
		q.push(i+1);
	}
	
    while (q.size() != 1) {
        q.pop(); //제일 위 버리기

        int tmp = q.front(); //제일 위를 마지막으로
        q.pop();
        q.push(tmp);
    }

	cout << q.back() << endl;
	return 0;
}