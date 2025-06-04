#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    int ans1 = 0; // 이진 변환 횟수
    int ans2 = 0; // 제거한 0의 개수

    while (s != "1") {
        // 1. 0 제거 & 카운팅
        string removed = "";
        for (char c : s) {
            if (c == '1') removed += '1';
            else ans2++; // 제거된 0 개수 누적
        }

        // 2. 문자열 길이를 이진수로 변환
        int len = removed.length();
        string binary = "";
        while (len > 0) {
            binary = to_string(len % 2) + binary;
            len /= 2;
        }

        s = binary; // 다음 반복을 위해 갱신
        ans1++;     // 변환 횟수 증가
    }

    return {ans1, ans2};
}