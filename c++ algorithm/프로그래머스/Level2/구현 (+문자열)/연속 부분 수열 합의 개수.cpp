#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    unordered_set<int> sums;

    // elements를 두 배로 복제
    vector<int> extended(elements.begin(), elements.end());
    extended.insert(extended.end(), elements.begin(), elements.end());

    // 길이 1부터 n까지 슬라이딩 윈도우
    for (int len = 1; len <= n; ++len) {
        int sum = 0;

        // 첫 윈도우 합 구하기
        for (int i = 0; i < len; ++i) {
            sum += extended[i];
        }
        sums.insert(sum);

        // 슬라이딩 윈도우
        for (int i = len; i < n + len - 1; ++i) {
            sum = sum - extended[i - len] + extended[i];
            sums.insert(sum);
        }
    }

    return sums.size();
}

