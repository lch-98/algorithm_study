#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotate90(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    vector<vector<int>> rotated(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[j][N - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        
        vector<vector<int>> maze(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> maze[i][j];
            }
        }
        
        vector<vector<int>> clock_90 = rotate90(maze);
        vector<vector<int>> clock_180 = rotate90(clock_90);
        vector<vector<int>> clock_270 = rotate90(clock_180);
        
        cout << "#" << tc << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << clock_90[i][j];
            }
            cout << " ";
            for (int j = 0; j < N; j++) {
                cout << clock_180[i][j];
            }
            cout << " ";
            for (int j = 0; j < N; j++) {
                cout << clock_270[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
