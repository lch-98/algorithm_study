#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> semester; // 해당학기마다 선수과목이 몇 개 들어가 있는지 체크하는 벡터
vector<int> prior; // 선수과목 처리후 각 과목마다 몇 학기 걸리는지 체크하는 벡터
void init()
{
	graph = vector<vector<int>>(N + 1);
	semester = vector<int>(N + 1, 0);
	prior = vector<int>(N + 1, 0);
}

void bfs()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (semester[i] == 0)
		{
			q.push(i);
			prior[i]++;
		}
	}

	while (!q.empty())
	{
		int curr_node = q.front();
		q.pop();
		for (int neighbor : graph[curr_node])
		{
			semester[neighbor]--;
			
			if (semester[neighbor] == 0)
			{
				q.push(neighbor);
				prior[neighbor] = prior[curr_node] + 1;
			}
		}
	}
	for (int i = 1; i < prior.size(); i++)
	{
		cout << prior[i] << " ";
	}
}

int main()
{
	cin >> N >> M;
	init();
	// A번 과목이 B번 과목 선수과목
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		semester[b]++;
	}
	bfs();
}