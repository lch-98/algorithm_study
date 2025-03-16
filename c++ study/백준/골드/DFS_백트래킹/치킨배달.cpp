#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int minCityChickenDistance = 21e8;
vector<pair<int, int>> houses; // 집들의 위치
vector<pair<int, int>> chickens; // 치킨집들의 위치
vector<int> combination; // 가능한 치킨집들 조합들

int calculateChickenDistance() {
    int totalDistance = 0;
    for (auto house : houses) {
        int houseDistance = 21e8;
        for (int i : combination) {
            int chickenDistance = abs(house.first - chickens[i].first) + abs(house.second - chickens[i].second);
            houseDistance = min(houseDistance, chickenDistance);
        }
        totalDistance += houseDistance;
    }
    return totalDistance;
}

void generateCombinations(int depth, int start) {
    if (depth == M) {
        int cityDistance = calculateChickenDistance();
        minCityChickenDistance = min(minCityChickenDistance, cityDistance);
        return;
    }

    for (int i = start; i < chickens.size(); i++) {
        combination[depth] = i;
        generateCombinations(depth + 1, i + 1);
    }
}

int main() {
    cin >> N >> M;

    // 도시 정보 입력받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value;
            cin >> value;
            if (value == 1) houses.push_back({ i, j });
            else if (value == 2) chickens.push_back({ i, j });
        }
    }

    combination = vector<int>(M,0);
    generateCombinations(0, 0);

    cout << minCityChickenDistance << "\n";
    return 0;
}