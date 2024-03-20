// 갤럭시 노트 그림 참조
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coin[101] = {};
int dp[10001] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}
	sort(coin + 1, coin + N + 1);

	fill(dp + 1, dp + K + 1, 1e9);

	// 단일 동전으로 만들 수 있는 개수 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j % coin[i] == 0)
				dp[j] = min(dp[j], j / coin[i]);	// 더 단위가 큰 동전으로 대체
		}
	}

	// 동전을 합쳐서 줄일 수 있는지 확인
	for (int i = 1; i <= K - 1; i++) {
		for (int j = i + 1; j <= K; j++) {
			if (i + j > K)
				break;
			dp[i + j] = min(dp[i + j], dp[i] + dp[j]);
		}
	}

	dp[K] == 1e9 ? cout << -1 : cout << dp[K];

	return 0;
}