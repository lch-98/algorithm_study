// 단순 그리디로 접근하니까 문제 발생 n이 5만일때 시간초과
// 따라서 투 포인터로 접근해야 함
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end()); // 오름차순 정렬
    int light = 0; // 가장 가벼운 사람 인덱스
    int heavy = people.size() - 1; // 가장 무거운 사람 인덱스
    int answer = 0;

    while (light <= heavy) {
        if (people[light] + people[heavy] <= limit) {
            light++; // 가벼운 사람 태움
        }
        // 무거운 사람은 항상 태워야 하므로
        heavy--;
        answer++;
    }

    return answer;
}
