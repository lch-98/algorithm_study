#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ChkminChange(string str, char num) {
	int cnt = 0;
	bool chk_flag = true;
	string chk_str = "";
	chk_str.append(str.length(), num); // 모두 1 or 0이 됐을 때, 체크 문자열을 만들어 놓음

	if (str == chk_str) chk_flag = false; // 맨 처음에 모두 1 or 0일 수도 있기 때문에 체크

	while (chk_flag) {
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == num) continue;
			else {
				for (int j = i; j < str.length(); j++)
				{
					if (str[j] == num) break;
					else str[j] = num;
				}
				cnt++;
			}
		}
		if (str == chk_str) chk_flag = false;
	}
	return cnt;
}

int main() {
	string str;
	cin >> str;

	int num_zero = ChkminChange(str, '0');
	int num_one = ChkminChange(str, '1');

	cout << min(num_zero, num_one) << "\n";
}