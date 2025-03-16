#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> lst;
	unordered_map<int, int> table;
	for (int i = 0; i < N; i++)
	{
		int startDay, endDay;
		cin >> startDay >> endDay;
		lst.push_back({ startDay, endDay });
	}
	
	// print
	for (int i = 0; i < lst.size(); i++)
	{
		for (int j = lst[i].first; j <= lst[i].second; j++)
		{
			table[j]++;
		}
	}
	
	int row_cnt = 0;
	int col_max = 0;
	int sum = 0;
	int flag = 0; // 다음 0이 아닌 지점을 찾는 곳
	for (int i = 0; i < table.size(); i++)
	{
		//cout << i << " " << table[i] << " // ";
		if (table[i] != 0)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}

		if (flag == 1)
		{
			row_cnt++;
			col_max = max(col_max, table[i]);
		}
		else
		{
			sum += col_max * row_cnt;
			col_max = 0;
			row_cnt = 0;
		}
	}
	sum += col_max * row_cnt;
	cout << sum;
}