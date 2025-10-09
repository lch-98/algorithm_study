#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> lst(n);

	for (int i = 0; i < n; i++)
	{
		cin >> lst[i];
	}
	long long m;
	cin >> m;

	sort(lst.begin(), lst.end());
	int left = 0;
	int right = lst[lst.size() - 1];
	
	int result, sum;
	while (left <= right) {
		sum = 0;
		int mid = (left + right) / 2;
		
		for (int i = 0; i < n; i++)
		{
			sum += min(lst[i], mid);
		}

		if (m >= sum) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result;

}