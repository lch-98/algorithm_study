#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int min_pos = 0;
		int prev_min_pos = 2100000000;
		vector<int> person_to_rockpos(N, 0);
		for (int j = 0; j < N; j++) {
			int rock_pos;
			cin >> rock_pos;

			min_pos = (abs(rock_pos) - 0);
			if (min_pos < prev_min_pos) prev_min_pos = min_pos;
			person_to_rockpos[j] = rock_pos;
		}
		int cnt = 0;
		for (int k = 0; k < N; k++) {
			if(prev_min_pos == abs(person_to_rockpos[k])) cnt++;
		}
		cout << "#" << i + 1 << " " << prev_min_pos << " " << cnt << "\n";
	}
	return 0;
}