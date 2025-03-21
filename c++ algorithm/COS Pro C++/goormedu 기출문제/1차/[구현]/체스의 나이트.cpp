// 하단과 같이 include 문을 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int dy[] = {1, -1, -2, 2, -2, 2, -1, 1};
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
unordered_map<char, int> change_pos(8);
int solution(string pos) {
	int answer = 0;

	change_pos = { {'A', 0}, {'B',1},{'C',2},{'D',3},{'E',4},{'F',5},{'G',6},{'H',7} };
	int col = change_pos[pos[0]];
	int row = abs(stoi(pos.substr(1,1)) - 8);

	for (int dr = 0; dr < 8; dr++)
	{
		int new_row = row + dy[dr];
		int new_col = col + dx[dr];
		if (new_row >= 0 && new_col >= 0 && new_row < 8 && new_col < 8)
		{
			answer++;
		}
	}
	return answer;
}


int main() {
	string pos = "A7";
	int ret = solution(pos);

	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}