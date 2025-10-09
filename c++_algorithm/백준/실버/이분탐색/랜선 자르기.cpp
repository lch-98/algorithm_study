// 2 2
// 1 1 예시가 division zero error 예시임
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	vector<long long> len(K);
	for (int i = 0; i < K; i++)
	{
		cin >> len[i];
	}
	sort(len.begin(), len.end());

	long long left = 1;
	long long right = len[len.size() - 1];
	int ans = 0;
	while (left <= right)
	{
		int cnt = 0;
		long long mid = (left + right) / 2;

		for (int i = 0; i < len.size(); i++)
		{
			cnt += len[i] / mid;
		}

		if (cnt >= N ) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
}