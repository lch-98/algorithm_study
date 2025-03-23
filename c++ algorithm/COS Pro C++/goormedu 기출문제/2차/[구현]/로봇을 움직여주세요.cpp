// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// "U:0" "D:1" "L:2" "R:3"
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
vector<int> solution(string commands) {
	vector<int> answer;
	pair<int, int> pos = { 0,0 };
	for (int i = 0; i < commands.size(); i++)
	{
		if (commands[i] == 'U')
		{
			pos.first += dy[0];
			pos.second += dx[0];
		}
		else if (commands[i] == 'D')
		{
			pos.first += dy[1];
			pos.second += dx[1];
		}
		else if (commands[i] == 'L')
		{
			pos.first += dy[2];
			pos.second += dx[2];
		}
		else if (commands[i] == 'R')
		{
			pos.first += dy[3];
			pos.second += dx[3];
		}
	}
	answer = {pos.second, pos.first};
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string commands = "URDDL";
    vector<int> ret = solution(commands);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 {";
    for(int i = 0; i < ret.size(); i++){
        if (i != 0) cout << ", ";
        cout << ret[i];
    }
    cout << "} 입니다." << endl;
}