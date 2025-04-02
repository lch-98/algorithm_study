#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> prices) {

	int INF = 1000000001;
	int tmp = INF;
	int answer = -INF;
	for (int price : prices) {
		if (tmp != INF)
			answer = max(answer, price - tmp);
		tmp = min(tmp, price);
	}
	return answer;
}

int main() {
	vector<int> prices1 = { 1, 2, 3 };
	int ret1 = solution(prices1);

	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<int> prices2 = { 3, 1 };
	int ret2 = solution(prices2);

	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}