// 월간 코드 챌린지 시즌2
// 비트 연산에 대한 이해 + 수학적 규칙
#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    answer.reserve(numbers.size());
    
    for (long long x : numbers) {
        if (x % 2 == 0) {
            // 짝수는 마지막 비트가 0이므로 단순히 +1
            answer.push_back(x + 1);
        } else {
            // 홀수는 01 → 10 패턴으로 변경
            long long bit = 1;
            while (x & bit) bit <<= 1; // 처음으로 0인 자리 찾기
            // 그 0을 1로, 바로 아래 1을 0으로 변경
            long long res = x + bit - (bit >> 1);
            answer.push_back(res);
        }
    }
    return answer;
}