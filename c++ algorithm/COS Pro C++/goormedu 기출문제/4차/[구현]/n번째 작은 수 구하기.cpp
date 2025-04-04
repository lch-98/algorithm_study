// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

string str = "";
unordered_set<int> combi;
void recursive(vector<int> card, vector<int> visited, int depth) {

	if (depth == card.size())
	{
		combi.insert(stoi(str));
		return;
	}

	for (int i = 0; i < card.size(); i++)
	{
		if (visited[i] == 1) continue;

		str += to_string(card[i]);
		visited[i] = 1;

		recursive(card, visited, depth + 1);

		str.pop_back();
		visited[i] = 0;
	}
}

int solution(vector<int> card, int n) {
	int answer = -1;

	vector<int> visited(card.size(), 0);
	recursive(card, visited, 0);
	
	vector<int> sortedCombi(combi.begin(), combi.end());
	sort(sortedCombi.begin(), sortedCombi.end());
	
	for (int i = 0; i < sortedCombi.size(); i++)
	{
		if (sortedCombi[i] == n) return i+1;
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	vector<int> card1 = { 1, 2, 1, 3 };
	int n1 = 1312;
	int ret1 = solution(card1, n1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<int> card2 = { 1, 1, 1, 2 };
	int n2 = 1122;
	int ret2 = solution(card2, n2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}