#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence;
void backtracking(int depth, int branch, int target_depth) {
	if (depth == target_depth) {
		for (int i = 0; i < sequence.size(); i++) {
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= branch; i++) {
		sequence.push_back(i);
		backtracking(depth + 1, branch, target_depth);
		sequence.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;

	backtracking(0, N, M);

	return 0;
}