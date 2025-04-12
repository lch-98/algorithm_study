// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool chk(vector<vector<int>> visited) {
	for (int i = 0; i < visited.size(); i++)
	{
		for (int j = 0; j < visited[i].size(); j++)
		{
			if (visited[i][j] == 0) { return false; }
		}
	}
	return true;
}

int solution(int n, vector<vector<int>> garden) {
	int answer = 0;
	vector<vector<int>> visited = vector<vector<int>>(n, vector<int>(n, 0));
	queue<pair<int, int>> q;

	for (int i = 0; i < garden.size(); i++)
	{
		for (int j = 0; j < garden[i].size(); j++)
		{
			if (garden[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };
	while (!q.empty()) {
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dr = 0; dr < 4; dr++)
		{
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] == 1) continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
		if (!chk(visited))
		{
			answer++;
		}
		else return answer;	
	}
}


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int n1 = 3;
	vector<vector<int>> garden1 = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
	int ret1 = solution(n1, garden1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int n2 = 2;
	vector<vector<int>> garden2 = { {1, 1}, {1, 1} };
	int ret2 = solution(n2, garden2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}