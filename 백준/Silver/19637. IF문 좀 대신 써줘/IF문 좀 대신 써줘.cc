#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<string, int>> title;

string search(int n, int start, int end) {
    string name = "wrong";

    while (start <= end) {

        int mid = (start + end) / 2;

        if (mid == 0) {
            //cout << "Case 1" << endl;
            if (n <= title[0].second)
                return title[0].first;
            else
                return title[1].first;
        }

        if (mid + 1 == N) {
            //cout << "Case 2" << endl;
            if (n == title[N-1].second)
                return title[N-1].first;
            else 
                return title[N-2].first;
        }

        if (title[mid-1].second < n && n <= title[mid].second) {
            return title[mid].first;
        }

        else if (title[mid].second < n && n <= title[mid+1].second) {
            return title[mid+1].first;
        }

        else if (n > title[mid].second) {
            start = mid;
        }

        else {
            end = mid;
        }
    }
    
    return name;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string name;
        int strength;
        cin >> name >> strength;
        title.push_back(make_pair(name, strength));
    }
    
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        string name;

        int start = 0, end = N - 1;
        name = search(n, start, end);

        cout << name << "\n";
    }
    return 0;
}