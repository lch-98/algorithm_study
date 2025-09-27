#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string lower(string str) {
    for (int i=0; i<str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') continue;
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
    }
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if (cacheSize == 0) return cities.size() * 5;

    for (string city : cities) {
        string transform_city = lower(city);

        auto it = find(cache.begin(), cache.end(), transform_city);

        if (it == cache.end()) { // cache miss
            if (cache.size() == cacheSize) {
                cache.erase(cache.begin()); // 가장 오래된 것 제거
            }
            cache.push_back(transform_city);
            answer += 5;
        } else { // cache hit
            cache.erase(it);          // 기존 위치에서 제거
            cache.push_back(transform_city);    // 맨 뒤에 다시 삽입 (최근 사용)
            answer += 1;
        }
    }
    return answer;
}