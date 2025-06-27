#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	
	vector<int> nx = { 2, 1 };
	queue<pair<long,int>> q;
	q.push({ A,1 });
	bool flag = false;
	while (!q.empty()) {
		long curr = q.front().first;
		int curr_cost = q.front().second;
		q.pop();

		if (curr == B) { 
			cout << curr_cost << "\n";
			flag = true;
			break; 
		}

		for (int dr = 0; dr < nx.size(); dr++)
		{
			long next = curr;
			if (nx[dr] == 1) { // 1이면 맨뒤에 1을 추가
				string temp = to_string(next);
				temp += to_string(nx[dr]);
				next = stol(temp);
			}
			else { // 2이면 *2 연산을 진행
				next *= nx[dr];
			}

			if (B < next) continue;
			q.push({ next, curr_cost + 1});
		}
	}
	if (!flag) cout << -1 << "\n";
	return 0;
}