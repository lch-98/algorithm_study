#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> prev, pair<int,int> rear) {
	if (prev.first != rear.first) return prev.first< rear.first;
	return prev.second < rear.second;
}

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> pos(n);
	for (int i = 0; i < n; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	sort(pos.begin(), pos.end(), compare);

	for (int i = 0; i < pos.size(); i++)
	{
		cout << pos[i].first << " " << pos[i].second << "\n";
	}

	return 0;
}