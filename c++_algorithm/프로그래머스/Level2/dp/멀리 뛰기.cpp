#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> dp(n + 1, 0);
    dp[1] = 1; // 1칸만 뛰는 경우 -> 1
    dp[2] = 2; // 2칸만 뛰는 경우 -> 1+1, 2
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    return dp[n];
}