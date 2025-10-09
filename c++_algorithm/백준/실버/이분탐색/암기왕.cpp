#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binary(vector<int>& notes1, int target) {
	int left = 0;
	int right = notes1.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (target == notes1[mid]) return true;
		else if (target > notes1[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		vector<int> notes1(N);
		for (int j = 0; j < N; j++)
		{
			cin >> notes1[j];
		}
		sort(notes1.begin(), notes1.end());
		int M; 
		cin >> M;
		vector<int> notes2(M);
		for (int k = 0; k < M; k++)
		{
			cin >> notes2[k];
			if (binary(notes1, notes2[k])) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
	return 0;
}