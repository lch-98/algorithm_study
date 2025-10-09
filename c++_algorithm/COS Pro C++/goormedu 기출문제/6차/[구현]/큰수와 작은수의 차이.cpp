// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr, int K) {
	// 여기에 코드를 작성해주세요.
	int answer = 0;
	sort(arr.begin(), arr.end());
	int min_diff = 1e9;

	for (int i = 0; i <= arr.size() - K; i++) {
		int diff = arr[i + K - 1] - arr[i];
		min_diff = min(min_diff, diff);
	}
	answer = min_diff;
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	vector<int> arr = {9, 11, 9, 6, 4, 19};
	int K = 4;
	int ret = solution(arr, K);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}