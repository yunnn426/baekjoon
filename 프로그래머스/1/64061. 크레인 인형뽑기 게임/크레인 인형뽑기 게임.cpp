#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, n = 0;
    n = board.size();
    
    vector<int> box; // 바구니
    for (int i = 0; i < moves.size(); i++) {
        int place = moves[i] - 1; // 뽑는 위치
        int doll = 0;
        
        // 뽑을 인형 찾기
        for (int j = 0; j < n; j++) {
            if (board[j][place] != 0) {
                doll = board[j][place]; 
                board[j][place] = 0; // 뽑으면 0이 됨
                break;
            }
        }
        if (doll == 0) // 뽑을 인형이 없으면 다음 
            continue;
        
        // 바구니에 추가
        if (!box.empty() && box[box.size() - 1] == doll) { // 뽑은거랑 바구니 제일 위에 있는거랑 같으면
            box.pop_back();
            answer += 2;
        }
        else {
            box.push_back(doll);
        }
    }
    
    return answer;
}