#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	queue<int> ans_q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K - 1; j++)
		{
			int curr_num = q.front();
			q.pop();
			q.push(curr_num);
		}
		int real_num = q.front();
		q.pop();
		ans_q.push(real_num);
	}

	cout << "<";
	while (!ans_q.empty()) {
		if (ans_q.size() == 1) {
			cout << ans_q.front();
			break;
		}
		cout << ans_q.front() << ", ";
		
		ans_q.pop();
	}
	cout << ">";
}