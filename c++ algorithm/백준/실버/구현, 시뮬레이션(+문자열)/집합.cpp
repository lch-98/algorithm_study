#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 금메달 수가 많은 나라
// 금메달 수 동일, 은메달 수가 많은 나라
// 금, 은메달 수 동일, 동메달 수가 많은 나라
bool compare(vector<int>& a, vector<int>& b) {
    if (a[1] == b[1]) {
        if (a[2] == b[2]) {
            return a[3] > b[3];
        }
        return a[2] > b[2];
    }
    return a[1] > b[1];
}

int main() {

    int N, K;
    cin >> N >> K;

    vector<vector<int>> nations;
    for (int i = 0; i < N; i++)
    {
        int num, gold, silver, bronze;
        cin >> num >> gold >> silver >> bronze;
        nations.push_back({ num, gold, silver, bronze });
    }
    sort(nations.begin(), nations.end(), compare);

    int ans = 1;
    for (int i = 0; i < nations.size(); i++)
    {
        if (i > 0) {
            if (!(nations[i][1] == nations[i - 1][1] && nations[i][2] == nations[i - 1][2] && nations[i][3] == nations[i - 1][3])) {
                ans = i + 1;
            }
        }

        if (nations[i][0] == K) {
            cout << ans;
            break;
        }
    }

    return 0;
}