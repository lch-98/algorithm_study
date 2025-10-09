#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 도난당했지만 여벌도 있는 학생 제거
    vector<int> realLost, realReserve;
    for (int l : lost) {
        if (find(reserve.begin(), reserve.end(), l) != reserve.end()) {
            // reserve에서도 제거
            reserve.erase(find(reserve.begin(), reserve.end(), l));
        } else {
            realLost.push_back(l);
        }
    }

    realReserve = reserve;

    int answer = n - realLost.size();

    for (int i = 0; i < realReserve.size(); i++) {
        for (int j = 0; j < realLost.size(); j++) {
            if (abs(realReserve[i] - realLost[j]) == 1) {
                answer++;
                realLost.erase(realLost.begin() + j);
                break;
            }
        }
    }

    return answer;
}