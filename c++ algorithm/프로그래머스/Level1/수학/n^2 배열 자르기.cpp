#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <= right; i++) {
        // 1차원 index i를 2차원 index (row, col)로 변환
        int row = i / n;
        int col = i % n;

        // 규칙에 따라 값 계산
        answer.push_back(max(row, col) + 1);
    }
    return answer;
}
