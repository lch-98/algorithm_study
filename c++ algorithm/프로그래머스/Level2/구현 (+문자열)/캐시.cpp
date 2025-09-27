#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if (cacheSize == 0) return cities.size() * 5;

    for (string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        auto it = find(cache.begin(), cache.end(), city);

        if (it == cache.end()) { // cache miss
            if (cache.size() == cacheSize) {
                cache.erase(cache.begin()); // 가장 오래된 것 제거
            }
            cache.push_back(city);
            answer += 5;
        } else { // cache hit
            cache.erase(it);          // 기존 위치에서 제거
            cache.push_back(city);    // 맨 뒤에 다시 삽입 (최근 사용)
            answer += 1;
        }
    }
    return answer;
}
