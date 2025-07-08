#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	vector<int> apple_pi(K);
	for (int i = 0; i < K; i++) {
		cin >> apple_pi[i];
	}
	apple_pi.insert(apple_pi.end(), apple_pi.begin(), apple_pi.end());

	int max_flavor = 0;
	int window_sum = 0;
	for (int i = 0; i < N; i++) {
		window_sum += apple_pi[i];
	}
	max_flavor = window_sum;

	for (int i = N; i < apple_pi.size(); i++)
	{
		window_sum = window_sum - apple_pi[i - N] + apple_pi[i];
		max_flavor = max(max_flavor, window_sum);
	}
	cout << max_flavor;
	return 0;
}