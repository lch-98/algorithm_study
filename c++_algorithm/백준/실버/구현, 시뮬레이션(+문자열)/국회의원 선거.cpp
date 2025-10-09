#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int answer = 0;
	int dasom = 0;
	vector<int> vote(N);
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cin >> dasom;
		}
		else if (i >= 1) {
			cin >> vote[i];
		}
	}
	while (1) {
		if (dasom > *max_element(vote.begin(), vote.end())) {
			break;
		}
		sort(vote.rbegin(), vote.rend());
		vote[0]--;
		dasom++;
		answer++;
	}
	cout << answer;
	return 0;
}

/* 우선순위 큐를 통한 풀이
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    int dasom;
    cin >> dasom;
    
    priority_queue<int> pq;
    for (int i = 1; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    
    int answer = 0;
    while (!pq.empty() && pq.top() >= dasom) {
        int top = pq.top(); pq.pop();
        top--; 
        dasom++;
        answer++;
        pq.push(top);
    }
    cout << answer;
}

*/