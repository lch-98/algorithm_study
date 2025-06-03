#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool chk_vps(string &str) {
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else {
			if (s.empty()) {
				return false;
			}
			s.pop();
		}
	}
	return s.size() == 0;
}

int main() {
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (chk_vps(str)) { cout << "YES" << "\n"; }
		else { cout << "NO" << "\n"; }
	}
	return 0;
}

/* 문자열 풀이
#include <iostream>
#include <string>
using namespace std;

bool chk_vps(string &str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') cnt++;
		else {
			cnt--;
			if (cnt < 0) return false;
		}
	}
	return cnt == 0; // if (cnt == 0) return true; 이렇게 하면 컴파일러 오류 발생
}

int main() {
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (chk_vps(str)) { cout << "YES" << "\n"; }
		else { cout << "NO" << "\n"; }
	}
	return 0;
}
*/