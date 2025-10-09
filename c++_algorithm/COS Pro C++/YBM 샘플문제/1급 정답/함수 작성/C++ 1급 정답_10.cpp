#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b) {
	if (a[1] != b[1]) return a[1] > b[1];  // 1. 자녀 유무 (1이 우선)
	if (a[2] != b[2]) return a[2] > b[2];  // 2. 자녀 수 많을수록 우선
	if (a[3] != b[3]) return a[3] > b[3];  // 3. 청약 점수 높은 순
	return a[0] < b[0];                    // 4. 고유번호 작은 순
}

vector<int> solution(vector<vector<int>> household) {
	vector<int> answer;
	sort(household.begin(), household.end(), compare);
	for (int i = 0; i < household.size(); i++)
	{
		answer.push_back(household[i][0]);
	}
	
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.
int main() {
	vector<vector<int>> household = { {1, 1, 2, 60}, {2, 1, 2, 85},	{3, 0, 0, 70}, {4, 0, 0, 70}, {5, 1, 3 , 90} };
	vector<int> ret = solution(household);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {" << ret[0] << ", " \
		<< ret[1] << ", " << ret[2] << ", " << ret[3] \
		<< ", " << ret[4] << "}입니다." << endl;
	return 0;
}
