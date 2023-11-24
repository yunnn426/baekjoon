#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, w, L;
    cin >> n >> w >> L;
    int truck[n];

    for (int i = 0; i < n; i++) {
        cin >> truck[i];
    }

    queue<int> bridge;
    for (int i = 0; i < w; i++) {
        bridge.push(0);
    }

    int weight = 0; //현재 다리 하중
    int i = 0;
    int time = 0;

    while (i < n) {
        time++;
        
        int out = bridge.front();
        weight -= out;
        bridge.pop();

        if (truck[i] + weight <= L) {
            bridge.push(truck[i]);
            weight += truck[i];
            i++;
        }
        else {
            bridge.push(0);
        }
    }

    cout << time + w << endl;

	return 0;
}