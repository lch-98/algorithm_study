#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, w, l;
vector<int> truck;
queue<int> q;
int main()
{
	cin >> n >> w >> l;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		truck.push_back(num);
	}
	
	int ans = 0;
	int weightSum = 0; // 다리 위의 트럭 무게의 합
	for (int i = 0; i < n; i++)
	{
		while (true) 
		{
			if (q.size() == w) 
			{
				weightSum -= q.front(); // 맨 앞의 트럭 제거
				q.pop();
			}
			if (truck[i] + weightSum <= l) 
			{
				break;
			}
			q.push(0); // 무게가 L을 넘는 경우
			ans++;
		}
		q.push(truck[i]);
		weightSum += truck[i];
		ans++;
	}
	cout << ans + w;
}