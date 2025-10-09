#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	vector<int> apple_pi(K);
	for (int i = 0; i < K; i++) {
		cin >> apple_pi[i];
	}
	apple_pi.insert(apple_pi.end(), apple_pi.begin(), apple_pi.end());

	int max_flavor = 0;
	int window_sum = 0;
	for (int i = 0; i < N; i++) {
		window_sum += apple_pi[i];
	}
	max_flavor = window_sum;

	for (int i = N; i < apple_pi.size(); i++)
	{
		window_sum = window_sum - apple_pi[i - N] + apple_pi[i];
		max_flavor = max(max_flavor, window_sum);
	}
	cout << max_flavor;
	return 0;
}

/* 원형 슬라이딩 윈도우 풀이법 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> apple_pi(N);
    for (int i = 0; i < N; i++) {
        cin >> apple_pi[i];
    }

    int window_sum = 0;
    for (int i = 0; i < K; i++) {
        window_sum += apple_pi[i];
    }

    int max_flavor = window_sum;

    for (int i = 1; i < N; i++) {
        // i: 윈도우 시작점
        window_sum -= apple_pi[(i - 1) % N];           // 앞에 빠지는 값
        window_sum += apple_pi[(i + K - 1) % N];       // 뒤에 추가되는 값
        max_flavor = max(max_flavor, window_sum);
    }

    cout << max_flavor;
    return 0;
}
*/