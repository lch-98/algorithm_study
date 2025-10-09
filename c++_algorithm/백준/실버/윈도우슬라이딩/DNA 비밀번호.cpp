#include <iostream>
#include <string>
using namespace std;

int A, C, G, T;
int A_cnt = 0, C_cnt = 0, G_cnt = 0, T_cnt = 0;
int ans = 0;

void update_count(char ch, int delta) {
    if (ch == 'A') A_cnt += delta;
    else if (ch == 'C') C_cnt += delta;
    else if (ch == 'G') G_cnt += delta;
    else if (ch == 'T') T_cnt += delta;
}

bool check_valid() {
    return A_cnt >= A && C_cnt >= C && G_cnt >= G && T_cnt >= T;
}

int main() {
    int S, P;
    cin >> S >> P;
    string str;
    cin >> str;
    cin >> A >> C >> G >> T;

    // 초기 윈도우 처리
    for (int i = 0; i < P; i++) {
        update_count(str[i], 1);
    }

    if (check_valid()) ans++;

    // 슬라이딩 윈도우
    for (int i = P; i < S; i++) {
        update_count(str[i - P], -1);  // 왼쪽 문자 제거
        update_count(str[i], 1);       // 오른쪽 문자 추가

        if (check_valid()) ans++;
    }

    cout << ans << '\n';
    return 0;
}
