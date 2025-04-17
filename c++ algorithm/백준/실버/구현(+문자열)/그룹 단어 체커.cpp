#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool group_chk(string str) {
	unordered_map<char, int> chk_duplicate;
	char prev = str[0];
	chk_duplicate[str[0]]++;

	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] != prev) {
			if (chk_duplicate[str[i]] >= 1) return false;
			prev = str[i];
		}
		chk_duplicate[str[i]]++;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if(group_chk(str)) answer++;
	}
	cout << answer;
}