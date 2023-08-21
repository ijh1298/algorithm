#include <iostream>
int dp[1001][3];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int N;
	std::cin >> N >> dp[0][0] >> dp[0][1] >> dp[0][2];

	for (int i = 1; i < N; ++i) {
		std::cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		//RGB거리 : 다이나믹 프로그래밍 문제
		//직전 세 값 중, 바로 위에 있지 않은 값이면서 최소값을 골라서 더함
		dp[i][0] += std::min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += std::min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += std::min(dp[i - 1][0], dp[i - 1][1]);
	}

	std::cout << std::min(dp[N - 1][0], std::min(dp[N - 1][1], dp[N - 1][2]));
	return 0;
}