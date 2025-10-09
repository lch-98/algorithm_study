#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> pos = {
	{'A', 0},
	{'B', 1},
	{'C', 2},
	{'D', 3},
	{'E', 4},
	{'F', 5},
	{'G', 6},
	{'H', 7},
};

unordered_map<int, char> reverse_pos = {
	{0, 'A'},
	{1, 'B'},
	{2, 'C'},
	{3, 'D'},
	{4, 'E'},
	{5, 'F'},
	{6, 'G'},
	{7, 'H'},
};

unordered_map<string, int> dr = {
	{"T", 0},
	{"B", 1},
	{"L", 2},
	{"R", 3},
	{"LT",4},
	{"RT",5},
	{"LB",6},
	{"RB",7},
};
// 상 하 좌 우 왼위 오위 왼아 오아
// T  B  L  R  LT   RT   LB   RB
int dy[] = {-1,1,0,0,-1,-1,1,1};
int dx[] = {0,0,-1,1,-1,1,-1,1};

int main() {
	string posK, posR;
	int N;
	cin >> posK >> posR >> N;
	// 생각하기 편하게 미리 0,0을 좌상단 7,7을 우하단으로 통일해서 문제 진행
	// 왕 위치
	int rowK = 8 - stoi(posK.substr(1, 1)); // 8이 가장 높음 즉, 0행에 위치해 있어야 함
	int colK = pos[posK[0]];

	// 돌 위치
	int rowR = 8 - stoi(posR.substr(1, 1)); 
	int colR = pos[posR[0]];

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;
		int num = dr[command];

		int nrowK = rowK + dy[num];
		int ncolK = colK + dx[num];
		// 킹이 범위 벗어나면 다시 처음부터
		if (nrowK < 0 || nrowK >= 8 || ncolK < 0 || ncolK >= 8) continue;
		// 킹이랑 돌이랑 위치가 같을 때
		if (nrowK == rowR && ncolK == colR) {
			int nrowR = rowR + dy[num];
			int ncolR = colR + dx[num];
			// 돌이 범위 벗어나면 다시 처음부터
			if (nrowR < 0 || nrowR >= 8 || ncolR < 0 || ncolR >= 8) continue;
			rowR = nrowR;
			colR = ncolR;
		}
		rowK = nrowK;
		colK = ncolK;
	}
	string king_pos = reverse_pos[colK] + to_string(8 - rowK);
	string rock_pos = reverse_pos[colR] + to_string(8 - rowR);
	cout << king_pos << "\n";
	cout << rock_pos;
	return 0;
}