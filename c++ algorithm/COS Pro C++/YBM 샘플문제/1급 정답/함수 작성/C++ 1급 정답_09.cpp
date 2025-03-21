#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> info, vector<vector<int>> game) {
	vector<bool> know_b(N, false); // 전략을 아는 사람 체크
	queue<int> q; // BFS를 위한 큐

	// 전략을 아는 사람들 초기화
	for (int person : info[1]) {
		know_b[person] = true;
		q.push(person);
	}

	while (!q.empty()) {
		int person = q.front();
		q.pop();

		for (int i = 0; i < game.size(); i++) 
		{
			// 경기 중 전략을 아는 사람이 있으면, 모든 참가자에게 전파
			bool found = false;
			for (int j = 0; j < game[i].size(); j++) 
			{
				if (know_b[game[i][j]] == true) 
				{
					found = true;
					break;
				}
			}
			if (found) 
			{
				for (int j = 0; j < game[i].size(); j++) 
				{
					if (know_b[game[i][j]] == false) 
					{
						know_b[game[i][j]] = true;
						q.push(game[i][j]);
					}
				}
			}
		}
	}

	// 전략을 모르는 사람이 있는 게임 카운트
	int result = 0;
	for (int i = 0; i < game.size(); i++) 
	{
		bool knows_strategy = false;
		for (int j = 0; j < game[i].size(); j++) 
		{
			if (know_b[game[i][j]] == true)
			{
				knows_strategy = true;
				break;
			}
		}
		if (knows_strategy == false) result++;
	}
	return result;
}


// 테스트 코드
int main() {
    int N1 = 5;
    vector<vector<int>> info1 = {{1}, {4}};
    vector<vector<int>> game1 = {{1, 2}, {3}, {3, 4}};

    int ret1 = solution(N1, info1, game1);
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    int N2 = 7;
    vector<vector<int>> info2 = {{3}, {1, 2, 3}};
    vector<vector<int>> game2 = {{1}, {2}, {3}, {4}, {5}, {6}, {4, 5}, {3, 6}};

    int ret2 = solution(N2, info2, game2);
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

    return 0;
}