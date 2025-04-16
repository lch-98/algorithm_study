#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int window_sum = 0;
	for (int i = 0; i < K; i++)
		window_sum += arr[i];  // 첫 윈도우 합

	int max_sum = window_sum;

	for (int i = K; i < N; i++) {
		window_sum = window_sum - arr[i - K] + arr[i];
		max_sum = max(max_sum, window_sum);
	}

	cout << max_sum;
}