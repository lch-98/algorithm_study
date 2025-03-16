#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> maze;
vector<int> visited;
void bfs(int start_node) {
	queue<int> q;
	q.push(start_node);
	visited[start_node] = 0; // 처음 시작에는 점프가 0이니까
	
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 1; i <= maze[curr]; i++)
		{
			int dist = curr + i;
			if (dist >= N + 1) continue;
			if (visited[dist] != 10000) continue;
			visited[dist] = visited[curr] + 1;
			q.push(dist);
		}
	}
}

int main() {
	cin >> N;
	
	maze = vector<int>(N+1, 0); // 첫 번째 칸이 1번칸으로 하기 위해서 (안헷갈리기 위해)
	visited = vector<int>(N + 1, 10000);
	for (int i = 1; i <= N; i++)
	{
		cin >> maze[i];
	}
	bfs(1);
	if (visited[N] == 10000) cout << -1;
	else cout << visited[N];
}