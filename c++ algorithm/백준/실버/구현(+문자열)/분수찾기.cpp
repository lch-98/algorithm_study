#include <iostream>
using namespace std;

int main() {
	// 홀수 대각선은 짝수의 합을 가짐
	// 짝수 대각선은 홀수의 합을 가짐
	int num;
	cin >> num;

	int digonal_line = 1;
	while (num - digonal_line > 0) {
		num -= digonal_line;
		digonal_line++;
	}

	if (digonal_line % 2 == 0) cout << num << "/" << digonal_line - num + 1 << "\n";
	else cout << digonal_line - num + 1 << "/" << num << "\n";

	return 0;
}