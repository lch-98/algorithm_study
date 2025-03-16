#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string str;
int max_sum = -21e8;
int calculator(int num1, int num2, char oper) {
	int temp = 0;

	if (oper == '+')
	{
		temp = num1 + num2;
	}
	else if (oper == '-')
	{
		temp = num1 - num2;
	}
	else
	{
		temp = num1 * num2;
	}
	return temp;
}

void backtracking(int depth, int sum) {
	
	if (depth >= n)
	{
		max_sum = max(max_sum, sum);
		return;
	}

	char oper = (depth == 0) ? '+' : str[depth - 1];

	// 괄호 없을 때
	backtracking(depth + 2, calculator(sum, str[depth] - '0', oper));
	
	// 괄호 있을 때
	if (depth + 2 < n)
	{
		int galho_sum = calculator(str[depth] - '0', str[depth + 2] - '0', str[depth + 1]);
		backtracking(depth + 4, calculator(sum, galho_sum, oper));
	}
}

int main() {
	cin >> n;
	cin >> str;
	backtracking(0, 0);
	cout << max_sum;
}