#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> graph;
vector<int> lst;
int cnt = 0;
void dfs(int depth, int target_depth, int start) {
	if (depth == target_depth)
	{
		int sum = 0;
		for (int i : lst)
		{
			sum += graph[i];
		}
		if (sum == S) cnt++;
		return;
	}

	for (int i = start; i < graph.size(); i++)
	{

		lst.push_back(i);
		dfs(depth + 1, target_depth, i + 1);
		lst.pop_back();
	}
}

int main() {
	cin >> N >> S;
	graph = vector<int>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> graph[i];
	}

	for (int depth = 1; depth <= N; depth++)
	{
		dfs(0, depth, 0);
	}
	cout << cnt;
}