#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> days;

	// 1. 각 작업마다 걸리는 일수를 계산
	for (int i = 0; i < progresses.size(); i++) {
		int remain = 100 - progresses[i];
		int day = (remain + speeds[i] - 1) / speeds[i]; // 올림 처리
		days.push_back(day);
	}

	// 2. 순서대로 배포 로직 적용
	int prev = days[0];
	int count = 1;

	for (int i = 1; i < days.size(); i++) {
		if (days[i] <= prev) {
			count++;
		}
		else {
			answer.push_back(count);
			count = 1;
			prev = days[i];
		}
	}
	answer.push_back(count);

	return answer;
}
