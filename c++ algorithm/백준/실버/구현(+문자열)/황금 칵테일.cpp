// 한양대학교 ERICA 캠퍼스 Zero One Algorithm Contest 2022 C번
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int M;
    cin >> M;

    unordered_map<string, int> ingredient_sum;
    for (int i = 0; i < M; ++i) {
        string name; int amount;
        cin >> name >> amount;
        ingredient_sum[name] += amount;  // 한 번에 총량 합산
    }

    vector<int> amounts;
    for (const auto& entry : ingredient_sum) {
        amounts.push_back(entry.second);
    }

    bool delicious = false;
    for (int i = 0; i < amounts.size(); ++i) {
        for (int j = i + 1; j < amounts.size(); ++j) {
            if (floor(amounts[i] * 1.618) == amounts[j] || amounts[i] == floor(amounts[j] * 1.618)) { delicious = true; break; }
        }
        if (delicious) break;
    }

    cout << (delicious ? "Delicious!" : "Not Delicious...") << "\n";
    return 0;
}