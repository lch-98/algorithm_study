#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int chk_binary(int n) {
    // 2진수 1의 갯수 판단 로직
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n = n / 2;
    }
    int cnt_one = count(binary.begin(), binary.end(), '1'); // 1 의 갯수
    return cnt_one;
}

int solution(int n) {
    int OriginalCntOne = 0;
    OriginalCntOne = chk_binary(n);
    int CompareCntOne = 0;
    while (1) {
        n++;
        CompareCntOne = chk_binary(n);
        if (OriginalCntOne == CompareCntOne) break;
    }
    return n;
}