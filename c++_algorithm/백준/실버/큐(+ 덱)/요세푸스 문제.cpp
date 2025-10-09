#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K; // 입력 받기
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	vector<int> circle;
	
	while (!q.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		circle.push_back(q.front());
		q.pop();
	}
	
	cout << "<";
	for (int i = 0; i < circle.size(); i++)
	{
		if (i == circle.size() -1)
		{
			cout << circle[i];
			break;
		}
		cout << circle[i] << ", ";
	}
	cout << ">";

	return 0;
}
