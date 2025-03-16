#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string str;
	cin >> str;
	
	vector<int> cnt_set(10, 0); // 6이랑 9랑 똑같이 보면됨
	for (int i = 0; i < str.size(); i++)
	{
		int num = str[i] - '0';
		cnt_set[num]++;
	}

	// 6과 9를 합쳐서 계산
	int six_nine_count = cnt_set[6] + cnt_set[9];
	cnt_set[6] = (six_nine_count + 1) / 2;  // 6과 9는 합쳐서 (짝수면 /2, 홀수면 +1하고 /2)
	cnt_set[9] = 0;  // 9는 따로 계산할 필요 없음 (이미 6에 포함)

	// 최댓값을 찾아 필요한 세트 수 계산
	int max_num = *max_element(cnt_set.begin(), cnt_set.end());

	cout << max_num;
}