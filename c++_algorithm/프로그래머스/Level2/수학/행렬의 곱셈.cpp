#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n = arr1.size();        // arr1 행 개수
    int m = arr1[0].size();     // arr1 열 개수 == arr2 행 개수
    int k = arr2[0].size();     // arr2 열 개수

    vector<vector<int>> answer(n, vector<int>(k, 0));

    for (int i = 0; i < n; i++) {        // 결과 행
        for (int j = 0; j < k; j++) {    // 결과 열
            for (int t = 0; t < m; t++) { 
                answer[i][j] += arr1[i][t] * arr2[t][j];
            }
        }
    }

    return answer;
}