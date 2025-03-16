#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 높은 곳의 상자를 낮은 곳에 옮기는 방식을 최고점과 최저점의 간격을 줄이는 평탄화
// 평탄화를 모두 수행하고 나면, 가장 높은 곳과 가장 낮은 곳의 차이가 최대 1 이내가 됨
int n;
vector<int> maze;
void simulate() {
	int max_item = *max_element(maze.begin(), maze.end());
	int min_item = *min_element(maze.begin(), maze.end());
	
	auto max_idx = find(maze.begin(), maze.end(), max_item);
	auto min_idx = find(maze.begin(), maze.end(), min_item);

	int rmax_idx = max_idx - maze.begin();
	int rmin_idx = min_idx - maze.begin();

	maze[rmax_idx]--;
	maze[rmin_idx]++;
}

int main() {
	for (int tc = 1; tc <= 10; tc++)
	{
		cin >> n;
		maze = vector<int>(100, 0);
		for (int i = 0; i < 100; i++)
		{
			cin >> maze[i];
		}
		for (int i = 0; i < n; i++)
		{
			simulate();
		}
		int max_item = *max_element(maze.begin(), maze.end());
		int min_item = *min_element(maze.begin(), maze.end());
		cout << "#" << tc << " " << max_item - min_item << "\n";
	}
}