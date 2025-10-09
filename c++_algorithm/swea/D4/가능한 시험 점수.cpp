#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> lst;
vector<int> visited;
int total_sum;
void init() {
	lst = vector<int>(n, 0);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		init();
		total_sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> lst[i];
			total_sum += lst[i];
		}
		visited = vector<int>(total_sum + 1, 0); // 총 가능한 점수 합의 visited 처리를 해줄 배열
		
		vector<int> ans = {0};
		for (int i = 0; i < lst.size(); i++)
		{
			vector<int> temp_lst;
			for (int j = 0; j < ans.size(); j++)
			{
				int sum_num = lst[i] + ans[j];
				if (visited[sum_num] != 0) continue;
				visited[sum_num] = 1;
				temp_lst.push_back(sum_num);
			}
			ans.insert(ans.end(), temp_lst.begin(), temp_lst.end());
		}
		cout << "#" << tc << " " << ans.size() << "\n";
	}
}