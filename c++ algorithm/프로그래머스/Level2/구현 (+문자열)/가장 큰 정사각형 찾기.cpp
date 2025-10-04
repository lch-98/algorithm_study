#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    int answer = 0;

    // 2D 누적합 만들기
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = board[i - 1][j - 1] 
                        + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    int limit = min(n, m);

    for (int size = limit; size >= 1; size--) { // 큰 정사각형부터 탐색
        bool found = false;
        for (int i = 0; i <= n - size; i++) {
            for (int j = 0; j <= m - size; j++) {

                // 내부 정사각형 합 계산
                int total = sum[i + size][j + size] - sum[i + size][j] - sum[i][j + size] + sum[i][j];

                // 정사각형 내부가 모두 1인지 확인
                if (total == size * size) {
                    answer = size;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) break;
    }

    return answer * answer;
}
