#include <iostream>
#include <vector>

using namespace std;

// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int K) {
	int answer = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i+1; j < arr.size(); j++)
		{
			for (int k = j+1; k < arr.size(); k++)
			{
				int sum = 0;
				sum += arr[i] + arr[j] + arr[k];
				if (sum % K == 0) answer++;
			}
		}
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int K = 3;
    int ret = solution(arr, K);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}

/* 구름IDE는 main함수를 수정하면 안됨
// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> combi_lst;
vector<int> combi;
void combination(int start, int depth, int branch_size) {

	if (depth == 3) {
		combi_lst.push_back(combi);
		return;
	}

	for (int i = start; i < branch_size; i++)
	{
		combi[depth] = i;
		combination(i + 1, depth + 1, branch_size);
	}
}

int solution(vector<int> arr, int K) {
	int answer = 0;
	
	for (int i = 0; i < combi_lst.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < combi_lst[0].size(); j++)
		{
			sum += combi_lst[i][j];
		}
		if (sum % K == 0) answer++;
	}

	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	vector<int> arr = { 1, 2, 3, 4, 5 };
	int K = 3;

	combi = vector<int>(3, 0); //서로 다른 3개 숫자 뽑기 위한 배열
	combination(0, 0, arr.size());

	int ret = solution(arr, K);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}
*/