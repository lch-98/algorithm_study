#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> num_lst;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	string str;
	cin >> str;
	
	int flag = 0; // 현재 부호는 +
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			flag = 1;
		}
		else if (str[i] == '+' && flag == 1)
		{
			str[i] = '-';
		}
	}

	int sum = 0;
	int start_idx = 0;
	int flag2 = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			if (flag2 == 0)
			{
				sum += stoi(str.substr(start_idx, i));
			}
			else if (flag2 == 1)
			{
				sum -= stoi(str.substr(start_idx, i));
			}
			flag2 = 1;
			start_idx = i + 1;
		}
		else if (str[i] == '+')
		{
			sum += stoi(str.substr(start_idx, i));
			start_idx = i + 1;
		}
	}
	
	if (flag2 == 0)
	{
		sum += stoi(str.substr(start_idx, str.size() - start_idx)); // 마지막 값
	}
	else if (flag2 == 1)
	{
		sum -= stoi(str.substr(start_idx, str.size() - start_idx)); // 마지막 값
	}
	cout << sum;

}