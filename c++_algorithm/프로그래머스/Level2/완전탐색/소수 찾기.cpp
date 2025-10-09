#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool chk_prime(int num) {
	if (num < 2) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;

	for (int i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

vector<vector<int>> permutation;
void back_tracking(int depth, int target, vector<int> &permu, vector<int> &visited, string &numbers) {
	if (depth == target) {
		permutation.push_back(permu);
		return;
	}

	for (int i = 0; i < numbers.length(); i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		permu.push_back(i);

		back_tracking(depth + 1, target, permu, visited, numbers);

		permu.pop_back();
		visited[i] = 0;
	}
}

int solution(string numbers) {
	int answer = 0;

	for (int i = 1; i <= numbers.size(); i++) {
		vector<int> visited(numbers.size(), 0);
		vector<int> permu;
		back_tracking(0, i, permu, visited, numbers);
	}

	unordered_set<int> delete_duplicate;
	for (int i = 0; i < permutation.size(); i++) {
		if (numbers[permutation[i][0]] == '0') continue; // 맨처음이 0이면 안됨

		string str = "";
		for (int j = 0; j < permutation[i].size(); j++) {
			str += numbers[permutation[i][j]];
		}
		// chk_prime 소수 체크
		int num = stoi(str);
		delete_duplicate.insert(num);
	}
	for (auto chk_num : delete_duplicate) {
		if (chk_prime(chk_num)) answer++;
	}

	return answer;
}
