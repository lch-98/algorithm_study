#include <iostream>
using namespace std;

int main() {
	long long N, M;
	cin >> N >> M;

	// N이 M보다 크거나 같으면 N!에는 M 이상의 숫자가 포함되어 있어서 나머지는 0
	if (N >= M) {
		cout << 0 << endl;
		return 0;
	}

	long long result = 1;
	for (long long i = 2; i <= N; i++) {
		result = (result % M) * (i % M) % M; // (result * i) % M;
		if (result == 0) { 
			break;
		}
	}

	cout << result << endl;
	return 0;
}
