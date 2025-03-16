#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const pair<char, int>& a, const pair<char, int>& b) {
	return a.second < b.second; // 등장 횟수(second)가 더 작은 것이 앞에 오도록 설정
}

int main() {
	string str;
	cin >> str;

	vector<pair<char, int>> count;
	for (int i = 0; i < str.size(); i++)
	{
		char a = str[i];

		// 대문자면 소문자 변경
		if (a >= 'A' && a <= 'Z') {
			a += ('a' - 'A');
		}
		// 카운트 하는 부분
		bool flag = false;
		for (int j = 0; j < count.size(); j++)
		{
			if (count[j].first == a)
			{
				count[j].second++;
				flag = true;
				break;
			}
		}

		if (flag == false) {
			count.push_back({ a, 1 });
		}
	}

	pair<char,int> max_it = *max_element(count.begin(), count.end(), compare); // compare 함수 사용
	char max_char = max_it.first;
	int max_cnt = max_it.second;

	int max_freq = 0;
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i].second == max_cnt)
		{
			max_freq++;
		}
	}

	if (max_freq > 1)
	{
		cout << "?" << "\n";
	}
	else
	{
		cout << char(max_char - ('a' - 'A')) << "\n";
	}
}	