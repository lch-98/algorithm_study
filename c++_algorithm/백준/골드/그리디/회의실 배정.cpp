#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> lst(N);
	for (int i = 0; i < N; i++)
	{
		cin >> lst[i].first >> lst[i].second;
	}
	sort(lst.begin(), lst.end(), compare);
	
	int last_time = 0;
	int cnt = 0;
	for (int i = 0; i < lst.size(); i++)
	{
		if (lst[i].first >= last_time)
		{
			cnt++;
			last_time = lst[i].second;
		}
	}
	cout << cnt;
}