#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> chobab(N);
    for (int i = 0; i < N; i++) {
        cin >> chobab[i];
    }

    vector<int> count(d + 1, 0); // 초밥 종류별 개수
    int kinds = 0;

    // 초기 윈도우
    for (int i = 0; i < k; i++) {
        if (count[chobab[i]] == 0) kinds++;
        count[chobab[i]]++;
    }

    int max_kind = kinds + (count[c] == 0 ? 1 : 0);

    // 슬라이딩 윈도우
    for (int i = 1; i < N; i++) {
        // 맨 앞 초밥 제거
        int remove = chobab[i - 1];
        count[remove]--;
        if (count[remove] == 0) kinds--;

        // 맨 뒤 초밥 추가 (원형 회전 고려)
        int add = chobab[(i + k - 1) % N];
        if (count[add] == 0) kinds++;
        count[add]++;

        int current_kind = kinds + (count[c] == 0 ? 1 : 0);
        max_kind = max(max_kind, current_kind);
    }

    cout << max_kind;
    return 0;
}
