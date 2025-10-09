#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num_lst;
int main() {
	int answer = 0;

	int n;
	cin >> n;

	// 입력 부분
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		num_lst.push_back(num);
	}
	int X;
	cin >> X;
	
	sort(num_lst.begin(), num_lst.end());
	int left = 0;
	int right = num_lst.size() - 1;
	while (left < right) {
		if (num_lst[left] + num_lst[right] == X) {
			answer++;
			left++;
			right--;
		}
		else if (num_lst[left] + num_lst[right] > X) {
			right--;
		}
		else if (num_lst[left] + num_lst[right] < X) {
			left++;
		}
	}
	cout << answer;
}