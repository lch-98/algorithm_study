#include <iostream>
#include <vector>
using namespace std;

int main() {
	//서로 다른 N개의 자연수의 합이 ->S
	//자연수 N의 최댓값은 얼마일까

	// 16이면 -> 1+2+3+4+6
	long long S;
	cin >> S;

	long long sum = 0, num = 1;
	int cnt = 0;

	while (true) {
		sum = sum + num;
		cnt++;
		if (sum > S) {
			cnt--;
			break;
		}
		num++;
	}
	cout << cnt;
}