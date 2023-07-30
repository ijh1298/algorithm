/*
* (이해 참고) https://omyodevelop.tistory.com/51
* 
* dp[0][i]는 max(dp[1][i - 1], dp[1][i - 2]) + m[0][i] 라는 점화식을 도출해내는 법을 알기
* 참고의 그림으로 보면 이해가 쉽다.
* 
*/

#include <iostream>
#include <algorithm>

using namespace std;
int m[2][100001];
int dp[2][100001];

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 1; i <= N; ++i)
			cin >> m[0][i];
		for (int i = 1; i <= N; ++i)
			cin >> m[1][i];

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = m[0][1];
		dp[1][1] = m[1][1];

		for (int i = 2; i <= N; ++i) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + m[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + m[1][i];
		}
		cout << max(dp[0][N], dp[1][N]) << '\n';
	}

	return 0;
}