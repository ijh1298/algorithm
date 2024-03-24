// 1715 카드 정렬하기와 거의 동일한 알고리즘
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int K;
		cin >> K;
		priority_queue<long long, vector<long long>, greater<long long>> pq;

		for (int i = 0; i < K; i++) {
			long long x;
			cin >> x;
			pq.push(x);
		}

		long long ans = 0;
		while (!pq.empty()) {
			if (pq.size() == 1)
				break;

			long long first = pq.top();
			pq.pop();

			long long second = 0;
			if (!pq.empty()) {
				second = pq.top();
				pq.pop();
			}

			ans += first + second;
			pq.push(first + second);
		}

		cout << ans << '\n';
	}

	return 0;
}