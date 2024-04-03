#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 300001

pair<int, int> jewel[MAX];
int bag[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}
	// 보석, 가방 오름차순 정렬
	sort(jewel, jewel + N);
	sort(bag, bag + K);

	priority_queue<long> maxValue;
	long long ans = 0;
	int ptr = 0;
	// !!! 한번 확인한 보석은 다시 볼 필요가 없다 !!!
	// 우선 순위 큐에 이미 담겨 있기 때문

	// 가치가 낮은 보석부터 가장 작은 가방에 넣기
	for (int i = 0; i < K; i++) {
			while (ptr < N && bag[i] >= jewel[ptr].first) {
				maxValue.push(jewel[ptr].second);
				ptr++;
			}
		if (!maxValue.empty()) {
			ans += maxValue.top();
			maxValue.pop();
		}
	}
	cout << ans;

	return 0;
}