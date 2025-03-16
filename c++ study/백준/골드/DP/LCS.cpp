#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int len1 = str1.length();
	int len2 = str2.length();

	// 2D DP 테이블 선언 및 초기화
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

	// 동적 계획법으로 LCS 구하기
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++) 
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1; // 문자가 같을 때
			}
			else 
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 문자가 다를 때
			}
		}
	}

	// LCS 길이 출력
	cout << dp[len1][len2] << endl;

	return 0;
}
