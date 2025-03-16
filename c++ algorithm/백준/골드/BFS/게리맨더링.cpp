#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> person;
vector<vector<int>> all_groupA;
vector<vector<int>> all_groupB;
vector<int> groupA;
vector<int> groupB;

bool isConnected(const vector<int> &group)
{
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	q.push(group[0]);
	visited[group[0]] = true;
	int count = 1; // 한 번 현재 노드를 카운트 하는거기 떄문에

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int neighbor = 1; neighbor < graph.size(); ++neighbor)
		{
			if (graph[node][neighbor] && visited[neighbor] == false && find(group.begin(), group.end(), neighbor) != group.end())
			{
				q.push(neighbor);
				visited[neighbor] = true;
				count++;
			}
		}
	}
	return count == group.size();
}

void simulate(int idx)
{
	if (idx == graph.size())
	{
		if (!groupA.empty() && !groupB.empty())
		{
			if (isConnected(groupA) && isConnected(groupB))
			{
				all_groupA.push_back(groupA);
				all_groupB.push_back(groupB);
			}
		}
		return;
	}
	
	groupA.push_back(idx);
	simulate(idx + 1);
	groupA.pop_back();

	groupB.push_back(idx);
	simulate(idx + 1);
	groupB.pop_back();
}

int main()
{
	cin >> N;
	person = vector<int>(N+1, 0);
	graph = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	
	for (int i = 1; i <= N; i++)
	{
		cin >> person[i];
	}
	for (int i = 1; i <= N; i++)
	{
		int M;
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			int node_num;
			cin >> node_num;
			graph[i][node_num] = 1;
		}
	}
	simulate(1);

	int groupdiff_min = 21e8;
	if (all_groupA.empty() && all_groupB.empty())
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < all_groupA.size(); i++)
	{
		int groupA_sum = 0;
		int groupB_sum = 0;
		for (auto Aid : all_groupA[i])
		{
			groupA_sum += person[Aid];
		}
		for (auto Bid : all_groupB[i])
		{
			groupB_sum += person[Bid];
		}
		groupdiff_min = min(abs(groupA_sum - groupB_sum), groupdiff_min);
	}
	cout << groupdiff_min;
}