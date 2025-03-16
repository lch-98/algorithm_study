#include <iostream>
#include <vector>
using namespace std;

int N, M, R;
vector<vector<int>> maze;

void operation1() {
	// 1번 연산: 상하 반전
	for (int i = 0; i < N / 2; i++) {
		swap(maze[i], maze[N - 1 - i]);
	}
}

void operation2() {
	// 2번 연산: 좌우 반전
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			swap(maze[i][j], maze[i][M - 1 - j]);
		}
	}
}

void operation3() {
	// 3번 연산: 오른쪽으로 90도 회전
	vector<vector<int>> new_maze(M, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			new_maze[j][N - 1 - i] = maze[i][j];
		}
	}
	maze = new_maze;
	swap(N, M);  // 행과 열의 크기를 교환
}

void operation4() {
	// 4번 연산: 왼쪽으로 90도 회전
	vector<vector<int>> new_maze(M, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			new_maze[M - 1 - j][i] = maze[i][j];
		}
	}
	maze = new_maze;
	swap(N, M);  // 행과 열의 크기를 교환
}

void operation5() {
	// 5번 연산: 1번 그룹을 2번으로, 2번을 3번으로, 3번을 4번으로, 4번을 1번으로 이동
	vector<vector<int>> new_maze(N, vector<int>(M));
	int halfN = N / 2, halfM = M / 2;

	for (int i = 0; i < halfN; i++) {
		for (int j = 0; j < halfM; j++) {
			new_maze[i][j + halfM] = maze[i][j];                 // 1번 -> 2번
			new_maze[i + halfN][j + halfM] = maze[i][j + halfM]; // 2번 -> 3번
			new_maze[i + halfN][j] = maze[i + halfN][j + halfM]; // 3번 -> 4번
			new_maze[i][j] = maze[i + halfN][j]; // 4번 -> 1번
		}
	}
	maze = new_maze;
}

void operation6() {
	// 6번 연산: 1번 그룹을 4번으로, 4번을 3번으로, 3번을 2번으로, 2번을 1번으로 이동
	vector<vector<int>> new_maze(N, vector<int>(M));
	int halfN = N / 2, halfM = M / 2;

	for (int i = 0; i < halfN; i++) {
		for (int j = 0; j < halfM; j++) {
			new_maze[i + halfN][j] = maze[i][j];  // 1->4
			new_maze[i + halfN][j + halfM] = maze[i + halfN][j];  // 4->3
			new_maze[i][j + halfM] = maze[i + halfN][j + halfM];  // 3->2
			new_maze[i][j] = maze[i][j + halfM];  // 2->1
		}
	}
	maze = new_maze;
}

int main() {
	cin >> N >> M >> R;
	maze = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		int operation;
		cin >> operation;
		switch (operation) {
		case 1: operation1(); break;
		case 2: operation2(); break;
		case 3: operation3(); break;
		case 4: operation4(); break;
		case 5: operation5(); break;
		case 6: operation6(); break;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}