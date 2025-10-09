#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	unordered_map<string, int> str_int_book;
	unordered_map<int, string> int_str_book;

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		str_int_book[str] = i;
		int_str_book[i] = str;
	}
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') {
			int str_int = stoi(str);
			cout << int_str_book[str_int] << "\n";
		}
		else {
			cout << str_int_book[str] << "\n";
		}
	} 
	return 0;
}