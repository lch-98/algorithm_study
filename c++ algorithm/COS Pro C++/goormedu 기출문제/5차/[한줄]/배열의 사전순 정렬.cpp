#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

vector<int> solution(vector<int> numbers) {
	
	vector<int> answer;
	
	sort(numbers.begin(), numbers.end());
	int mid = (numbers.size() - 1) / 2;
	swap(numbers[mid], numbers[numbers.size()-1]); // 1, 2, 3, 7, 5, 6, 4

	int left = mid + 1; // 4
	int right = numbers.size() - 2; // 5
	while(left <= right) {
		swap(numbers[left], numbers[right]); // 1 2 3 7 5 6 4
		left = left + 1; // 5
		right = right - 1; // 4
	}

	answer = numbers;
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.
int main() {
	vector<int> numbers = {7, 3, 4, 1, 2, 5, 6};
	vector<int> ret = solution(numbers);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 [";
	for(int i = 0; i < ret.size(); i++) {
		if(i != 0)
			cout << ", ";
		cout << ret[i];
	}
	cout << "] 입니다." << endl;
}