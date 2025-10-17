// 2018 KAKAO BLIND RECRUITMENT
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void print_(vector<string> board) {
    for (int i=0; i<board.size(); i++) {
        cout << board[i] << "\n";
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool changed = true;

    while (changed) {
        changed = false;
        vector<vector<bool>> erase(m, vector<bool>(n, false));
        // 1. 블록찾기
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char c = board[i][j];
                if (c == '0') continue;
                if (board[i+1][j] == c && board[i][j+1] == c && board[i+1][j+1] == c) {
                    erase[i][j] = erase[i+1][j] = erase[i][j+1] = erase[i+1][j+1] = true;
                    changed = true;
                }
            }
        }

        if (!changed) break;

        // 2. 블록 제거
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (erase[i][j]) {
                    board[i][j] = '0';
                    answer++;
                }
            }
        }
        //print_(board);
        //cout << "\n";
        // 3. 아래로 떨어뜨리기
        for (int j = 0; j < n; j++) { // 열
            int empty = m - 1;
            for (int i = m - 1; i >= 0; i--) { // 행
                if (board[i][j] != '0') {
                    swap(board[i][j], board[empty][j]);
                    empty--;
                }
            }
            //for (int k = empty; k >= 0; k--) board[k][j] = '0';
        }
        //print_(board);
        //cout << "\n";
    }
    return answer;
}
