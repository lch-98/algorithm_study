#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> visited;

int countLeafNodes(int root) {
	queue<int> q;
	q.push(root);
	visited[root] = 1;

	int leafCount = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		bool isLeaf = true;
		for (int child : graph[node]) {
			if (visited[child] == 0) {
				visited[child] = 1;
				q.push(child);
				isLeaf = false;
			}
		}

		// 자식 노드가 없으면 리프 노드로 간주
		if (isLeaf == true) {
			leafCount++;
		}
	}

	return leafCount;
}

int main() {
	cin >> N;
	graph = vector<vector<int>>(N);
	visited = vector<int>(N, 0);
	// 트리 구조기 때문에 단방향
	int root;
	for (int child_node = 0; child_node < N; child_node++) {
		int parent_node;
		cin >> parent_node;

		if (parent_node == -1) {
			root = child_node;  // 루트 노드 저장
		}
		else {
			graph[parent_node].push_back(child_node);  // 부모에 자식 추가
		}
	}

	int cut_nodeIdx;
	cin >> cut_nodeIdx;

	// 루트 노드가 잘리면 트리 전체가 삭제됨
	if (cut_nodeIdx == root) {
		cout << 0 << endl;
	}
	else {
		visited[cut_nodeIdx] = 1;  // 삭제된 노드로 간주
		int result = countLeafNodes(root);
		cout << result << endl;
	}

	return 0;
}
