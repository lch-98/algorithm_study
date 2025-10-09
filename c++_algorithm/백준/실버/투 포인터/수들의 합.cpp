#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> lst;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		lst.push_back(num);
	}

	int left = 0, right = 0, sum = 0, count = 0;

	while (true) {
		if (sum >= M) {
			sum -= lst[left++];
		}
		else if (right == N) {
			break;
		}
		else if (sum < M) {
			sum += lst[right++];
		}

		if (sum == M) count++;
	}
	cout << count;
}