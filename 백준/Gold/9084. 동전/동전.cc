#include <iostream>
using namespace std;

int dp[10001] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	cin >> T;
	while (T--) {
		fill(dp, dp + 10001, 0);
		dp[0] = 1;

		int coin[20] = {};
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> coin[i];

		cin >> M;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) {
				// X 원이 되는 방법 (백준 2293 동전 1 참조)
				// X - coin원에서 coin원을 더하면 된다
				// X - coin원은 DP에 의해 저장되어 있다
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
		cout << dp[M] << '\n';
	}

	return 0;
}