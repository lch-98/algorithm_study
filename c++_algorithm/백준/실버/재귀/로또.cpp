#include <iostream>
#include <vector>
using namespace std;

vector<int> answer(6,0);
void recursive(int depth, int start, vector<int> &S) {
	if (depth == 6) {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < S.size(); i++) {
		answer[depth] = S[i];
		recursive(depth + 1, i + 1, S);
	}
}

int main() {
	while (1) {
		int k;
		cin >> k;
		if (k == 0) break;
		else {
			vector<int> S(k);
			for (int i = 0; i < k; i++) {
				cin >> S[i];
			}
			recursive(0, 0, S);
			cout << "\n";
		}
	}
	return 0;
}