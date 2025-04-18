#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> count_map;

    // 1. 크기별 개수 세기
    for (int size : tangerine) {
        count_map[size]++;
    }

    // 2. 개수만 모아서 정렬
    vector<int> counts;
    for (auto& entry : count_map) {
        counts.push_back(entry.second);
    }

    sort(counts.begin(), counts.end(), greater<>()); // 내림차순

    // 3. 많이 나오는 종류부터 선택
    int kinds = 0;
    for (int count : counts) {
        k -= count;
        kinds++;
        if (k <= 0) break;
    }

    return kinds;
}