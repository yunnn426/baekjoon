#include <iostream>
#include <cstring>

using namespace std;

int N;

void push(int arr[], int i) {
    for (int j = i - 1; j <= i + 1; j++) {
        if (j >= 0 && j < N) {
            arr[j] = 1 - arr[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int *start = new int[N];
    int *end = new int[N];

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        start[i] = c - '0';
    }

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        end[i] = c - '0';
    }

    //시작과 목표가 같은 경우
    bool isSame = true;
    for (int i = 0; i < N; i++) {
        if (start[i] != end[i]) {
            isSame = false;
            break;
        }
    }
    if (isSame) {
        cout << "0\n";
        return 0;
    }
    
    int answer;

    int answer1 = 0;
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        arr[i] = start[i];
    }

    //0번 스위치 안누름
    for (int i = 0; i < N; i++) {
        if (arr[i] != end[i]) {
            if (i == N - 1)
                push(arr, i);
            else 
                push(arr, i + 1);
            answer1++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] != end[i]) {
            answer1 = -1;
            break;
        }
    }

    //0번 스위치 누름
    int answer2 = 1;
    for (int i = 0; i < N; i++) {
        arr[i] = start[i];
    }
    push(arr, 0);

    for (int i = 0; i < N; i++) {
        if (arr[i] != end[i]) {
            if (i == N - 1)
                push(arr, i);
            else
                push(arr, i + 1);
            answer2++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] != end[i]) {
            answer2 = -1;
            break;
        }
    }

    if (answer1 == -1)
        answer = answer2;
    else if (answer2 == -1)
        answer = answer1;
    else 
        answer = min(answer1, answer2);

    cout << answer << "\n";

    delete[] start; start = nullptr;
    delete[] end; end = nullptr;
    delete[] arr; arr = nullptr;
    
    return 0;
}