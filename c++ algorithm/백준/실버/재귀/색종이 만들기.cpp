#include <iostream>
#include <vector>
using namespace std;

int white = 0;
int blue = 0;

vector<vector<int>> paper;

// 모든 칸이 같은 색인지 확인
bool isSameColor(int x, int y, int size) {
    int color = paper[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != color)
                return false;
        }
    }
    return true;
}

// 재귀 분할
void countPaper(int x, int y, int size) {
    if (isSameColor(x, y, size)) {
        if (paper[x][y] == 0) white++;
        else blue++;
        return;
    }

    int half = size / 2;
    countPaper(x, y, half);               // 1사분면
    countPaper(x, y + half, half);        // 2사분면
    countPaper(x + half, y, half);        // 3사분면
    countPaper(x + half, y + half, half); // 4사분면
}

int main() {
    int N;
    cin >> N;
    paper.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> paper[i][j];

    countPaper(0, 0, N);

    cout << white << '\n' << blue << '\n';

    return 0;
}
