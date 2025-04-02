// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> pos = { {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7} };
int solution(vector<string> bishops) {
	int answer = 0;
	vector<vector<int>> visited(8, vector<int>(8, 0));

	for (int i = 0; i < bishops.size(); i++)
	{
		int curr_row = abs(stoi(bishops[i].substr(1, 1)) - 8);
		int curr_col = pos[bishops[i][0]];
		visited[curr_row][curr_col] = 1;

		// 좌측 대각선
		for (int j = -7; j < 8; j++)
		{
			int nrow = curr_row + j;
			int ncol = curr_col + j;
			if (nrow >= 0 && ncol >= 0 && nrow < 8 && ncol < 8 && visited[nrow][ncol] != 1)
			{
				visited[nrow][ncol] = 1;
			}
		}

		// 우측 대각선
		for (int j = -7; j < 8; j++)
		{
			int nrow = curr_row - j;
			int ncol = curr_col + j;
			if (nrow >= 0 && ncol >= 0 && nrow < 8 && ncol < 8 && visited[nrow][ncol] != 1)
			{
				visited[nrow][ncol] = 1;
			}
		}
	}
	// 카운트하기
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(visited[i][j] == 1) answer++;
		}
	}

	return 64 - answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	vector<string>  bishops1 = { "D5" };
	int ret1 = solution(bishops1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<string>  bishops2 = { "D5", "E8", "G2" };
	int ret2 = solution(bishops2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}