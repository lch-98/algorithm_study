#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int answer = 0;
	int N, M, K;
	cin >> N >> M >> K;

	vector<string> chair(N);
	for (int i = 0; i < N; i++) {
		cin >> chair[i];
	}

	string chk_chair = "";
	for (int i = 0; i < K; i++) {
		chk_chair += '0';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M-K; j++) {
			if (chair[i].substr(j, K) == chk_chair) answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}